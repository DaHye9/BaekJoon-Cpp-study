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

int n, m,s,p, stscc, sn[500000], sccin[500000], cnt, sccnum,dfsn[500000],scccash[500000],finished[500000], cash[500000], smax[500000];
vector <int> adj[500000], sccadj[500000];
vector <vector<int>> scc;
bool rest[500000], sccrest[500000], canreach[500000];
stack<int> st;

int dfs(int curr) {
	dfsn[curr] = ++cnt;
	st.push(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0) result = min(result, dfs(next));
		else if (!finished[next]) result = min(result, dfsn[next]);
	}

	bool flag = false;

	if (result == dfsn[curr]) {
		vector<int> currscc;
		while (1) {
			int t = st.top();
			st.pop();
			if (t == s) stscc = sccnum;
			currscc.push_back(t);
			finished[t] = 1;
			sn[t] = sccnum;
			flag |= rest[t];
			scccash[sccnum] += cash[t];
			if (t == curr)break;
		}
		sccrest[sccnum] = flag;
		scc.push_back(currscc);
		sccnum++;
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a - 1].push_back(b - 1);
	}
	for (int i = 0; i < n; i++) {
		scanf("%d", &cash[i]);
	}

	scanf("%d %d", &s, &p);
	for (int i = 0; i < p; i++) {
		int a;
		scanf("%d", &a);
		rest[a - 1] = true;
	}

	for (int i = 0; i < n; i++) {
		if (dfsn[i] == 0) dfs(i);
	}

	//for (int i = 0; i < sccnum; i++) printf("%d\n", scccash[i]);
	for (int i = 0; i < n; i++) {
		for (int curr : adj[i]) {
			if (sn[i] != sn[curr]) {
				sccadj[sn[i]].push_back(sn[curr]);
				sccin[sn[curr]]++;
			}
		}
	}
	s--;
	queue <int> q;
	
	for (int i = 0; i < sccnum; i++) {
		smax[i] = scccash[i];
		if (sccin[i] == 0)q.push(i);
	}

	canreach[sn[s]] = true;

	while (!q.empty()) {
		int sccnum = q.front();
		q.pop();

		//printf("%d %d\n", sccnum, scccash[sccnum]);
		for (int next : sccadj[sccnum]) {
			if (canreach[sccnum]) {
			smax[next] = max(smax[next], smax[sccnum] + scccash[next]);
			canreach[next] = true;
			}
			if (--sccin[next] == 0) {
				q.push(next);
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < sccnum; i++) {
		if (sccrest[i] == true && canreach[i])ans = max(ans, smax[i]);
		//printf("%d\n", scccash[i]);
	}
	printf("%d", ans);

	return 0;
}