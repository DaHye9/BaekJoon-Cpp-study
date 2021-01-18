#include <cstdio>
#include <algorithm>
using namespace std;

int dp[1000001];

int f(int a) {
	if (a == 1) return 0;
	if (dp[a] != -1) return dp[a];

	int result = f(a - 1) + 1;

	if (a % 3 == 0) {
		result = min(result, f(a / 3) + 1);
	}
	if (a % 2 == 0) {
		result = min(result, f(a / 2) + 1);
	}
	dp[a] = result;
	
	return result;
}

int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < 1000001; i++) dp[i] = -1;
	printf("%d", f(n));
	return 0;
}