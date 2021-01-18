#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int n, m, s, e, time[10003], indegree[10003], visit[10003], num;
vector <pii> graph[10003], revgraph[10003];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		graph[a].push_back({ b,c });
		revgraph[b].push_back({ a,c });
		indegree[b]++;
	}
	scanf("%d %d", &s, &e);

	queue <int> q;
	q.push(s);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		for (int i = 0; i < graph[curr].size(); i++) {
			int next = graph[curr][i].first; int t = graph[curr][i].second;
			time[next] = max(time[next], time[curr] + t);
			if (--indegree[next] == 0) {
				q.push(next);
			}
		}
			
	}

	queue <int> q2;
	q2.push(e);
	visit[e] = 1;

	while (!q2.empty()) {
		int curr = q2.front();
		q2.pop();
		for (int i = 0; i < revgraph[curr].size(); i++) {
			int next = revgraph[curr][i].first; int t = revgraph[curr][i].second;
			if (time[next] == time[curr] - t) {
				//printf("%d %d\n", curr, next);
				num++;
				if (next != e && !visit[next]) {
					visit[next] = 1;
					q2.push(next);
				}
			}
		}
	}

	printf("%d\n%d", time[e], num);
}