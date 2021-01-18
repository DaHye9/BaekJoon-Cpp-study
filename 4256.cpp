#include <cstdio>

int n, t;
int pre[1010];
int mid[1010];

void f(int s, int e, int p) {
	for (int i = s; i < e; i++) {
		if (pre[p] == mid[i]) {
			f(s, i, p + 1);
			f(i + 1, e, p + i - s + 1); //p : pre에서의 루트노드 위치, 오른쪽 서브트리의 루트는 왼쪽 서브트리의 노드 개수 더해진 만큼임
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