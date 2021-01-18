#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
char result[81];
int state;

int checkvalid(int cnt) {
	for (int i = 0; i < cnt; i++) {
		for (int j = 1; j <= (cnt - i + 1) / 2; j++) {
			if (strncmp(&result[i], &result[i + j], j) == 0) return 0;
		}
	}
	return 1;
}

void backtracking(int cnt) {

	for (int i = 1; i < 4; i++) {
		int t = i + '0';
		result[cnt] = t;
		if (checkvalid(cnt) == 0) continue;
		//printf("%s\n", result);
		if (cnt == n - 1) {
			printf("%s", result);
			state = 1;
			return;
		}
		if (state == 1) return;
		backtracking(cnt + 1);
	}
}

int main() {
	scanf("%d", &n);

	backtracking(0);
}