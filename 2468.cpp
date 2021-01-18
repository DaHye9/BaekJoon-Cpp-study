#include <algorithm>
#include <cstdio>
using namespace std;

int ans = 1; //모두다 높이가 1인경우 가능함. 최소 ans는 1임.
int now = 0;
int n;
int arr[100][100];
int check[100][100];
int maxh = 0;

void dfs(int a, int b) {
	check[a][b] = 0;
	if (a - 1 >= 0 && check[a - 1][b] == 1) dfs(a - 1, b);
	if (a + 1 < n && check[a + 1][b] == 1) dfs(a + 1, b);
	if (b - 1 >= 0 && check[a][b - 1] == 1) dfs(a, b - 1);
	if (b + 1 < n && check[a][b + 1]) dfs(a, b + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int k = 0; k < n; k++) {
			scanf("%d", &arr[i][k]);
			maxh = max(maxh, arr[i][k]);
		}
	}

	for (int k = 1; k <= maxh; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (arr[i][j] > k) check[i][j] = 1;
				else check[i][j] = 0;
			}
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == 1) {
					dfs(i, j);
					now++;
				}
			}
		}
		//printf("%d", now);
		ans = max(ans, now);
		now = 0;
	}

	printf("%d", ans);
}