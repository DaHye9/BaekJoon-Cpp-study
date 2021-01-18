#include <cstdio>
#include <algorithm>
using namespace std;

int t;
int n;
int testcase[2][1000001];
int dp[1000001][3];

int f(int c, int status) {
	if (c == n) return 0;
	if (dp[c][status] != -1) return dp[c][status];

	dp[c][status] = f(c + 1, 0);
	if (status != 1) dp[c][status] = max(dp[c][status], f(c + 1, 1) + testcase[0][c]);
	if (status != 2) dp[c][status] = max(dp[c][status], f(c + 1, 2) + testcase[1][c]);
	
	return dp[c][status];
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < 2; j++) {
			for (int k = 0; k < n; k++){
				scanf("%d", &testcase[j][k]);
			}
		}
		for (int j = 0; j < n; j++) {
			dp[j][0] = -1;
			dp[j][1] = -1;
			dp[j][2] = -1;
		}
		printf("%d\n", f(0, 0));
	}

	return 0;
}