#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#define pii pair <int,int>
using namespace std;

int t, n, m, k;
vector <pair<int, pii>> ticket[101];
int arr[101][10001];
priority_queue < pair<int, pii>, vector<pair<int, pii>>, greater<pair<int, pii>>> pq;
//시간, 시작점, 비용

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		for (int j = 0; j < 101; j++) {
			for (int l = 0; l < 10001; l++) {
				arr[j][l] = 1000000;
			}
		}
		arr[1][0] = 0;
		scanf("%d %d %d", &n, &m, &k);
		for (int j = 0; j < k; j++) {
			int a, b, c, d;
			scanf("%d %d %d %d", &a, &b, &c, &d);
			ticket[a].push_back({ b,{c,d} });
		}//벡터 : 연결점, 비용, 소요시간
		pq.push({ 0,{1,0} });//소요시간, 시작점, 비용
		while (!pq.empty()) {
			int d = pq.top().first; int a = pq.top().second.first;
			int b = pq.top().second.second;
			pq.pop();
			if (arr[a][b] < d)continue;
			//printf("시작점 소요시간 비용%d %d %d\n", a, d, b);

			for (auto next : ticket[a]) {
				int j = next.first; int l = next.second.first; int p = next.second.second;
				/*if (arr[j][b] > arr[a][b] + l) {
					arr[j][b] = arr[a][b] + l;
					pq.push({ arr[j][b], {j,b} });
				}*/
				if (b + l <= m) {
					if (arr[j][b + l] > arr[a][b] + p) {
						arr[j][b + l] = arr[a][b] + p;
						pq.push({ arr[j][b+l], {j,b + l} });
					}
				}
			}
		}
		int ans = 1000000;
		for (int i = 0; i <= m; i++) {
			ans = min(ans, arr[n][i]);
		}
		ans == 1000000 ? printf("Poor KCM\n") : printf("%d\n", ans);
		while (!pq.empty()) pq.pop();
		for (int i = 0; i < n; i++)ticket[i].clear();
	}
}