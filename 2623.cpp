#include <iostream>
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

int n, m;
int edgenum[1003];

int main() {
	scanf("%d %d", &n, &m);
	vector<int> adj[1003];

	for (int i = 0; i < m; i++) {
		int t, prev, curr;
		scanf("%d", &t);

		if (t == 0) continue;

		scanf("%d", &prev);

		for (int j = 1; j < t; j++) {
			scanf("%d", &curr);
			edgenum[curr - 1]++;
			adj[prev - 1].push_back(curr - 1);
			prev = curr;
		}
	}

	queue<int> q;
	int ans[1003];

	for (int i = 0; i < n; i++) {
		if (edgenum[i] == 0) q.push(i);
	}

	for (int i = 0; i < n; i++) {
		if (q.empty()) {
			printf("0");
			return 0;
		}

		int temp = q.front();
		q.pop();
		ans[i] = temp + 1;

		for (int j = 0; j < adj[temp].size(); j++) {
			if (--edgenum[adj[temp][j]] == 0) q.push(adj[temp][j]);
		}
	}

	for (int i = 0; i < n; i++) {
		printf("%d\n", ans[i]);
	}

	return 0;
}