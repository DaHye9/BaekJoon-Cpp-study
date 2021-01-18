#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#define pii pair <int,int>
using namespace std;

priority_queue <pair<long long, pii>, vector<pair<long long, pii>>, greater<pair<long long, pii>>> pq;
int n, m, k;
long long Max = (long long)100000*1000000;
long long arr[10001][21];
vector <pii> road[10001];

void f(int now, int cnt, int k) {
	/*if (cnt >= ans)return;
	if (k < 0) return;
	if (visited[now])return;
	if (now == n) {
		ans = cnt;
		return;
	}
	visited[now] = 1;
	//printf("%d %d %d\n", now, cnt, k);
	for (int i = 0; i < road[now].size(); i++) {
		f(road[now][i].first, cnt + road[now][i].second, k);
		f(road[now][i].first, cnt, k - 1);
	}
	visited[now] = 0;*/

}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	int a, b, c;
	for (int i = 0; i < 10001; i++) {
		for (int j = 0; j < 21; j++) {
			arr[i][j] = Max;
		}
	}

	for (int i = 0; i < m; i++) {
		scanf("%d %d %d", &a, &b, &c);
		road[a].push_back({ b,c }); road[b].push_back({ a,c });
	}

	arr[1][k] = 0;
	pq.push({ 0 ,{1, k} });
	while(!pq.empty()) {
		long long d = pq.top().first;
		int now = pq.top().second.first; int temp = pq.top().second.second;
		pq.pop();
		if (d > arr[now][temp]) continue;

		for (auto j : road[now]) {
			int next = j.first; int d = j.second;
			if (arr[next][temp] > arr[now][temp] + d) {
				arr[next][temp] = arr[now][temp] + d;
				pq.push({ arr[next][temp],{next,temp} });
			}
			if (temp > 0) {
				if (arr[next][temp - 1] > arr[now][temp]) {
					arr[next][temp - 1] = arr[now][temp];
					pq.push({ arr[next][temp - 1],{next,temp - 1} });
				}
			}
		}
	}
	long long ans = Max;
	for (int i = 0; i <= k; i++) {
		ans = min(ans, arr[n][i]);
	}
	printf("%lld", ans);
}