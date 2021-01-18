#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <map>
#include <iostream>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int n, link, cnt, dfsn[2500], scccnt, sccnum[2500], finished[2500], sccin[2500], sccorder[2500];
ll score[2500];
map <string, int> m;
vector <int> adj[2500];
vector<int> sccadj[2500];
vector <vector<int>> scc;
stack <int> s;

int dfs(int curr) {
	dfsn[curr] = ++cnt;
	s.push(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0)result = min(result, dfs(next));
		else if (!finished[next])result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr]) {
		vector <int> scccurr;
		while (1) {
			int t = s.top();
			s.pop();
			scccurr.push_back(t);
			finished[t] = true;
			sccnum[t] = scccnt;
			if (t == curr)break;
		}
		scc.push_back(scccurr);
		scccnt++;
	}
	return result;
}

int main() {
	cin >> n;
	map <string, int> ::iterator it;
	for (int i = 0; i < n; i++) {
		string now; int k, to, from;
		cin >> now >> k;
		it = m.find(now);
		if (it != m.end()) to = it->second;
		else m[now] = to = link++;

		for (int j = 0; j < k; j++) {
			string have;
			cin >> have;
			it = m.find(have);
			if (it != m.end()) from = it->second;
			else m[have] = from = link++;
			adj[from].push_back(to);
		}
	}

	for (int i = 0; i < link; i++)if (dfsn[i] == 0)dfs(i);

	for (int i = 0; i < link; i++) {
		int snow = sccnum[i];
		for (int j : adj[i]) {
			int snext = sccnum[j];
			if (snow == snext)continue;
			sccadj[snow].push_back(snext);
			sccin[snext]++;
		}
	}

	for (int i = 0; i < 2500; i++)score[i] = 1;

	queue <int> q;
	for (int i = 0; i < scccnt; i++) {
		if (sccin[i] == 0)q.push(i);
	}
	for (int i = 0; i < scccnt; i++) {
		int curr = q.front();
		q.pop();
		sccorder[i] = curr;
		for (int next : sccadj[curr]) {
			if (--sccin[next] == 0)q.push(next);
		}
	}

	for (int i = 0; i < scccnt; i++) {
		for (int j : scc[sccorder[i]]) {
			for (int k : adj[j]) {
				if (sccnum[k] != sccnum[j])score[k] += score[j];
			}
		}
	}

	//for (int i = 0; i < link; i++)cout << score[i] << endl;

	string want;
	cin >> want;
	it = m.find(want);
	if (it != m.end())cout << score[it->second];
	else cout << 1;

	return 0;
}