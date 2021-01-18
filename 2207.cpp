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
#include <set>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int n, m, cnt, scc[20000], dfsn[20000], sccnum, result[20000];
vector <int> adj[20000];
bool finished[20000];
stack <int> s;

int opposite(int n) {
	return n % 2 ? n - 1 : n + 1;
}

int dfs(int curr) {
	dfsn[curr] = ++cnt;
	int result = dfsn[curr];
	s.push(curr);
	
	for (int next : adj[curr]) {
		if (dfsn[next] == 0)result = min(result, dfs(next));
		else if (!finished[next])result = min(result, dfsn[next]);
	}

	if (result >= dfsn[curr]) {
		scc[curr] = sccnum++;
		while (1) {
			int t = s.top();
			s.pop();
			finished[t] = true;
			if (t == curr)break;
			scc[t] = scc[curr];
		}
	}
	return result;
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		a = (a < 0 ? -(a + 1) * 2 : a * 2 - 1);
		b = (b < 0 ? -(b + 1) * 2 : b * 2 - 1);
		adj[opposite(a)].push_back(b);
		adj[opposite(b)].push_back(a);
	}

	for (int i = 0; i < n * 2; i++)
		if(dfsn[i]==0) dfs(i);


	for (int i = 0; i < n; i++) {
		if (scc[i * 2] == scc[i * 2 + 1]) {
			printf("OTL");
			return 0;
		}
	}

	printf("^_^");
	
}