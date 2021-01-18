#include <cstdio>

int n, t;
int pre[1010];
int mid[1010];

void f(int s, int e, int p) {
	for (int i = s; i < e; i++) {
		if (pre[p] == mid[i]) {
			f(s, i, p + 1);
			f(i + 1, e, p + i - s + 1); //p : pre������ ��Ʈ��� ��ġ, ������ ����Ʈ���� ��Ʈ�� ���� ����Ʈ���� ��� ���� ������ ��ŭ��
			printf("%d ", pre[p]);
		}
	}
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int j = 0; j < n; j++) {
			scanf("%d", &pre[j]);
		}
		for (int j = 0; j < n; j++) {
			scanf("%d", &mid[j]);
		}
		f(0, n, 0);
		printf("\n");
	}
}