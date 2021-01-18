#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <utility>
#define pii pair <int,int>
long long INF = 1e18;
using namespace std;

int n, start, en, m;
vector <pii> adj[101];
long long earn[101];

int main() {
	long long ans[102];
	scanf("%d %d %d %d", &n, &start, &en, &m);
	for (int i = 0; i < n; i++)ans[i] = -INF;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		scanf("%d %d %d", &a, &b, &c);
		adj[a].push_back({ b,c });
	}
	for (int i = 0; i < n; i++) scanf("%lld", &earn[i]);

	ans[start] = earn[start];

	for (int l = 0;l < 2; l++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (auto& p : adj[j]) {
					int next = p.first;
					long long k = p.second;
					if (ans[j] == -INF) continue;
					else if(ans[next] < ans[j] - k + earn[next]) {
						ans[next] = ans[j] - k + earn[next];
						if (l)ans[next] = INF;//한번 더 돌림으로써 양의 싸이클 있으면 그거 체크
					}
					else if (ans[j] == INF)ans[next] = INF;
					
				}
			}
		}
	}

	if (ans[en] == INF)printf("Gee");
	else if (ans[en] == -INF)printf("gg");
	else printf("%lld", ans[en]);
}