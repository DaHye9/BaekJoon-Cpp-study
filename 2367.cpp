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

int n, m, need[103], indegree[103], outdegree[103];
vector<pii> relation[103];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		relation[a].push_back({ b,c });
		indegree[b]++; outdegree[a]++;
	}
	queue<int> q;
	q.push(n);
	need[n]++;

	while (!q.empty()) {
		int curr = q.front();
		q.pop();

		//printf("%d %d\n", curr, need[curr]);

		for (int i = 0; i < relation[curr].size(); i++) {
			pii next = relation[curr][i];
			need[next.first] += need[curr] * next.second;
			if (--indegree[next.first] == 0 && outdegree[curr] != 0) q.push(next.first);
		}
		if(outdegree[curr]!=0) need[curr] = 0;
	}

	for (int i = 1; i <= n; i++) {
		if (need[i] != 0)printf("%d %d\n", i, need[i]);
	}
}