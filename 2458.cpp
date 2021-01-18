#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <math.h>

using namespace std;

typedef pair<int, int> pii;


//adjacency matrix�� �̿��ϸ� ���� �� ���ٴ� ����. ������ ã�� ���̴ϱ�, �׷������ �����ؼ� �̾��� �ִ��� Ȯ���ϸ� �� �� ���ٶ�� ����.
//�ᱹ �÷��̵� �ͼ�

int n, m, ans, visit[503];
int adj[503][503];

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < m; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a][b] = 1;
	}

	for (int k = 1; k <= n; k++) {
		adj[k][k] = 1;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adj[i][j] |= (adj[i][k] && adj[k][j]);
			}
		}
	}

	memset(visit, 1, sizeof(visit));
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			//printf("%d ", adj[i][j]);
			visit[i] &= (adj[i][j] || adj[j][i]);
		}
		//printf("\n");
		if (visit[i]) ans++;
	}
	
	printf("%d\n", ans);
}