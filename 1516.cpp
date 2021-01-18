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

int n, ans[503], time[503], num[503];
vector<int> indegree[503];

int main() {
	scanf("%d", &n);

	for (int i = 1; i <= n; i++) {
		scanf("%d", &time[i]);

		int a;
		scanf("%d", &a);

		while (a != -1) {
			num[i]++;
			indegree[a].push_back(i);
			scanf("%d", &a);
		}
	}

	queue<pii> q;
	for (int i = 1; i <= n; i++) {
		//printf("%d\n", num[i]);
		if (num[i] == 0) {
			q.push({ time[i],i });
			ans[i] = time[i];
		}
	}

	while (!q.empty()) {
		pii curr = q.front();
		q.pop();
		//printf("%d %d\n", curr.first, curr.second);
		for (int k = 0; k < indegree[curr.second].size(); k++) {
			int next = indegree[curr.second][k];
			ans[next] = max(ans[next], ans[curr.second] + time[next]);
			if (--num[next] == 0) q.push({ ans[next],next });
		}
	}

	for (int i = 1; i <= n; i++) {
		printf("%d\n", ans[i]);
	}
}