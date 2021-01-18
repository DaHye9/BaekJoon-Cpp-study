#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
/*
int dp[101][10001], coin[10001];
int n, k;

int f(int a, int b) { //a:쓸코인,b:남은가격
	//printf("%d %d\n", a, b);

	if (a == n) {
		if (b == 0) {
			return 0;
		}
		else {
			return 9999999;
		}
	}

	//printf("%d %d\n", a, b);

	if (dp[a][b] != -1) return dp[a][b];

	int result = f(a + 1, b);

	if (b >= coin[n])
		result = min(result, f(a, b - coin[a]) + 1);

	dp[a][b]=result;
	//printf("%d %d\n", a, b);


	return dp[a][b];
}

int main() {
	scanf("%d %d", &n, &k);

	for (int i = 0; i < n; i++) {
		scanf("%d", &coin[i]);
	}

	//sort(coin, coin + n);

	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			dp[i][j] = -1;
		}
	}
	int result = f(0, k);
	if (result != 9999999) {
		printf("%d", result);
	}
	else {
		printf("-1");
	}
	
	return 0;
}
*/
#include <cstdio>
#include <algorithm>
using namespace std;
const int MAX_N = 101;
const int MAX_K = 10001;
const int IMPOSSIBLE = 1000000000;

int N, K, cost[MAX_N], dp[MAX_N][MAX_K];

int coin(int n, int k) {
	if (n == N) return (k == 0 ? 0 : IMPOSSIBLE); // base case
	if (dp[n][k] != -1) return dp[n][k]; // 이미 계산됨

	int result = coin(n + 1, k);
	if (k >= cost[n]) result = min(result, coin(n, k - cost[n]) + 1);
	dp[n][k] = result; // dp 배열 값 갱신
	return result;
}

int main() {
	scanf("%d %d", &N, &K);
	for (int i = 0; i < N; i++)
		scanf("%d", cost + i);
	// dp 배열 초기화
	for (int i = 0; i <= N; i++)
		for (int j = 0; j <= K; j++)
			dp[i][j] = -1;
	// dp로 문제 품
	int result = coin(0, K);
	if (result == IMPOSSIBLE) puts("-1");
	else printf("%d\n", result);
}