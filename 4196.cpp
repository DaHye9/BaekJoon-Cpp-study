#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int t, n, m, cnt, sccnum, visit[100001], dfsn[100001], parent[100001],indegreenum[100001];
vector <int> adj[100001];
vector <vector<int>> scc;
stack <int> s;


int dfs(int curr) {
	dfsn[curr] = ++cnt;
	s.push(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0)result = min(result, dfs(next));
		else if (!visit[next])result = min(result, dfsn[next]);
	}

	if (result == dfsn[curr]) {
		vector<int> scccurr;
		while (1) {
			int t = s.top();
			s.pop();
			scccurr.push_back(t);
			visit[t] = 1;
			parent[t] = sccnum;
			if (t == curr)break;
		}
		scc.push_back(scccurr);
		sccnum++;
	}
	return result;
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d %d", &n, &m);
		for (int i = 0; i <= n; i++)adj[i].clear();

		for (int i = 0; i < m; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			adj[a].push_back(b);
		}

		while (!s.empty())s.pop();
		cnt = sccnum = 0;
		memset(visit, 0, sizeof(visit));
		memset(dfsn, 0, sizeof(dfsn));
		memset(parent, 0, sizeof(parent));
		memset(indegreenum, 0, sizeof(indegreenum));

		for (int i = 1; i <= n; i++) {
			if (dfsn[i] == 0)dfs(i);
		}

		for (int i = 1; i <= n; i++) {
			for (int j : adj[i]) {
				if (parent[i] != parent[j])indegreenum[parent[j]]++;
			}
		}

		int ans = 0;
		for (int i = 0; i < sccnum; i++) {
			if (indegreenum[i] == 0)ans++;
		}
		printf("%d\n", ans);
	}
}