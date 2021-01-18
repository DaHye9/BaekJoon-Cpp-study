#include <cstdio>
#include <algorithm>
#include <vector>
#include <math.h>
#include <string.h>
#define pii pair<int,int>
using namespace std;

char input[10][11];
vector<pii> len;
int visited[26];
int cnt[26];
int n;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%s", &input[i][0]);
		int temp = strlen(input[i]);
		for (int j = 0; j < temp; j++) {
			cnt[input[i][j] - 'A'] += pow(10, (temp - j - 1));
			//printf("%d\n", cnt[input[i][j] - 'A']);
		}
	}
	for (int i = 0; i < 26; i++) {
		if (cnt[i] == 0)visited[i] = 1;
	}
	for (int i = 9; i >= 0; i--) {
		int tmax = 0;
		int idx = -1;
		for (int j = 0; j < 26; j++) {
			if (visited[j])continue;
			if (tmax < cnt[j]) {
				tmax = cnt[j];
				idx = j;
			}
		}
		if (idx != -1) {
			visited[idx] = 1;
			cnt[idx] *= i;
		}
	}

	int result = 0;

	for (int i = 0; i < 26; i++)
		result += cnt[i];

	printf("%d", result);
}