#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int t, m, n, k;
int ans = 0;
int input[2501][2501];

void check(int a, int b) {
	if (input[a][b] == 0) return;
	input[a][b] = 0;

	//printf("%d %d\n", a, b);

	if (a + 1 < m) check(a + 1, b);
	if (a - 1 >= 0)check(a - 1, b);
	if (b + 1 < n)check(a, b + 1);
	if (b - 1 >= 0)check(a, b - 1);
}

int main() {
	scanf("%d", &t);
	for (int l = 0; l < t; l++) {
		scanf("%d %d %d", &m, &n, &k);
		for (int i = 0; i < k; i++) {
			int a, b;
			scanf("%d %d", &a, &b);
			input[a][b] = 1;
		}

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				if (input[i][j] == 1) {
					check(i, j);
					ans++;
				}
			}
		}
		printf("%d\n", ans);
		ans = 0;
	}
}