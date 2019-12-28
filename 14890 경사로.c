#include <stdio.h>

int main() {
	int n, m;
	int list[100];
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		scanf("%d", &list[i]);
	}

	int max = 0;

	for (int i = 0; i < n - 2; i++) {
		for (int j = i + 1; j < n - 1; j++) {
			for (int k = j + 1; k < n; k++) {
				int temp = list[i] + list[j] + list[k];
				if (temp <= m && max < temp) {
					max = temp;
				}
			}
		}
	}
	printf("%d", max);
	return 0;
}