#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <math.h>

using namespace std;

typedef pair<int, int> pii;

int n, ans, time[21][21], road[21][21];

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i ++) {
		for (int j = 0; j < n; j++) {
			scanf("%d", &time[i][j]);
			road[i][j] = time[i][j];
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (i == j) continue;
			for (int k = 0; k < n; k++) {
				if (i == k || j == k)continue;
				if (time[i][k] + time[k][j] == time[i][j])road[i][j] = road[j][i] = 0;
				else if (time[i][k] + time[k][j] < time[i][j]) {
					printf("-1");
					return 0;
				}
			}
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			//printf("%d ", road[i][j]);
			ans += road[i][j];
		}
		//printf("\n");
	}

	printf("%d\n", ans);
}