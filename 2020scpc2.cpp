#include <iostream>
#include <cstring>

using namespace std;

int ans = 0, n, k;
int dp[3002][3002];
int x[3002], y[3002];

int f(int a, int b) {
	if (a > n || b > n) return 0;
	//cout << a << " " << b << " " <<  ans << endl;
	if (dp[a][b] != -1) {
		//if (!visited[a][b]) ans += dp[a][b];
		//visited[a][b] = 1;
		return dp[a][b];
	}
	//visited[a][b] = 1;
	int tempa = a - 1; int tempb = b - 1;
	int suma = x[a]; int sumb = y[b];
	dp[a][b] = 0;
	while (suma <= k && tempa >= 0 && dp[a][b]==0) {
		dp[a][b] |= (!f(tempa,b));
		suma += x[tempa];
		tempa--;
	}
	while (sumb <= k && tempb >= 0 && dp[a][b]==0) {
		dp[a][b] |= (!f(a,tempb));
		sumb += y[tempb];
		tempb--;
	}

	/*if (!visited[a][b]) {
		ans += dp[a][b];
		visited[a][b] = 1;
	}*/
	return dp[a][b];
}

int main(int argc, char** argv)
{
	int T, test_case;
	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n >> k;
		for (int i = 1; i <= n; i++) {
			cin >> x[i];
		}
		for (int i = 1; i <= n; i++) {
			cin >> y[i];
		}
		memset(dp, -1, sizeof(dp));
		dp[0][0] = dp[0][2] = dp[2][0] = dp[1][1] = 1;
		dp[0][1] = dp[1][0] = 0;

		if (x[1] + x[2] <= k) dp[2][1] = 1;
		else dp[2][1] = 0;
		if (y[1] + y[2] <= k) dp[1][2] = 1;
		else dp[1][2] = 0;

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				f(i, j);
			}
		}

		for (int i = 0; i <= n; i++) {
			for (int j = 0; j <= n; j++) {
				//cout << i << " " << j << " " << dp[i][j] << endl;
				ans += dp[i][j];
			}
		}
		

		cout << "Case #" << test_case + 1 << endl;
		cout << ans << " " << (n+1)*(n+1) - ans << endl;

		ans = 0;
	}

	return 0;
}