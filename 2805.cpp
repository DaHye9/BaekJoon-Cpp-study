#include <cstdio>
#include <algorithm>
using namespace std;

int n, m;
int input[1000001];

int main() {
	scanf("%d %d", &n, &m);
	int maxn = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
		maxn = max(maxn, input[i]);
	}

	int start = 0;
	int end = maxn;

	while (1) {
		if (start + 1 >= end) {
			printf("%d", start);
			break;
		}
		int test = (start + end) / 2;
		long long total = 0;
		for (int i = 0; i <= n; i++) {
			if (input[i] > test) total += (input[i] - test);
		}
		//printf("%d %d\n", end, start);

		if (total >= m)start = test;
		else end = test;


		//printf("%d %d\n", end, start);
	}
}