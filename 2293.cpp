#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cstring>
#define pii pair<int,int>
#define MAX 30000000
using namespace std;

int n, k, curarr[10001], prevarr[10001], coin[101];

void dp(int a) {
	if (a == n)return;
	memcpy(prevarr, curarr, sizeof(curarr));
	//printf("%d\n", prevarr[0]);
	for (int i = 1; i <= k; i++) {
		for (int j = 1; j <= k; j++) {
			if (i - coin[a] * j >= 0)curarr[i] += prevarr[i - coin[a] * j];
			else break;
		}
	}
	dp(a + 1);
}

int main() {
	scanf("%d %d", &n, &k);
	curarr[0] = 1;
	for (int i = 0; i < n; i++) scanf("%d", &coin[i]);
	dp(0);
	printf("%d", curarr[k]);
}