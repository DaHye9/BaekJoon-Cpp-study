#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

typedef pair<int, int> pii;


int visit[501];
int dist[501];
int rem[501][501];

int n, m, s, d;

void dijkstra(vector<pii> (&adj)[501]) {
	priority_queue <pii, vector<pii>, greater<pii>> pq;
	dist[s] = 0;
	pq.push({ 0, s });
	while (!pq.empty()) {
		pii curr;
		do {
			curr = pq.top();
			pq.pop();
		} while (!pq.empty() && visit[curr.second]);

		if (visit[curr.second]) break;

		visit[curr.second] = 1;
		
		for (unsigned int i = 0; i < (unsigned)adj[curr.second].size(); i++) {
			int next = adj[curr.second][i].first, d = adj[curr.second][i].second;
			if (rem[curr.second][next]) continue;
			if (dist[next] > dist[curr.second] + d) {
				dist[next] = dist[curr.second] + d;
				pq.push({ dist[next],next });
				//printf("%d\n", next);
				//trace[next].clear();
				//trace[next].push_back(curr.second);
			}
			else if (dist[next] == dist[curr.second] + d) {
				//trace[next].push_back(curr.second);
			}
		}
	}
}

//dfs로 풀었는데 시간초과가 떠버렸다.. 아마도 시간초과 아니면 맞을 듯.

bool remove(vector<pii> (&adj)[501], int curr) {
	bool result = false;
	if(curr==d) return true;
	for (vector<pii>::iterator it = adj[curr].begin(); it != adj[curr].end();it++) {
		if (dist[it->first] == it->second + dist[curr]) {
			bool temp = remove(adj, it->first);
			result |= temp;
			if (temp) {
				//printf("%d %d %d\n", curr, it->first, it->second);
				rem[curr][it->first] = 1;
			}
		}
	}
	return result;
}

//그래서 처음에 생각했던 뒤에서부터 trace하는 bfs를 만들었다. 몇 줄 추가해야 돼서 안했던 건데, 몇 십줄을 더 추가하게 생겼다.^^ dfs는 이런 문제에서 느리다. 하지말자..

void tracing(vector<pii> (&revadj)[501], int curr){
	for (vector<pii>::iterator it = revadj[curr].begin(); it != revadj[curr].end(); it++) {
		if (rem[it->first][curr]) continue;
		if (dist[it->first] == dist[curr] - it->second) {
			rem[it->first][curr] = 1;
			//printf("%d %d\n", it->first, curr);
			tracing(revadj, it->first);
		}
	}
	/*
	queue<int> q;

	q.push(curr);
	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		
		for (int i = 0; i < trace[curr].size(); i++) {
			int next = trace[curr][i];
			rem[next][curr] = 1;
			//printf("%d %d\n", next, curr);
			q.push(next);
		}
		*/
}

int main() {
	while (1) {
		scanf("%d %d", &n, &m);
		if (m == 0 && n == 0) return 0;
		scanf("%d %d", &s, &d);

		vector<pii> adj[501], revadj[501];
		//vector<int> trace[501];
		for (int i = 0; i < 501; i++) {
			dist[i] = 100000000;
			visit[i] = 0;
		}
		memset(rem, 0, sizeof(rem));

		int a, b, c;
		for (int i = 0; i < m; i++) {
			scanf("%d %d %d", &a, &b, &c);
			adj[a].push_back({ b, c });
			revadj[b].push_back({ a,c });
		}

		dijkstra(adj);
		if (dist[d] == 100000000) {
			printf("-1\n");
			continue;
		}

		tracing(revadj, d);

		for (int i = 0; i < 501; i++)dist[i] = 100000000;
		memset(visit, 0, sizeof(visit));

		dijkstra(adj);
		printf("%d\n", dist[d]==100000000? -1:dist[d]);
	}
}