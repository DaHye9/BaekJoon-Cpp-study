#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <math.h>

using namespace std;

typedef pair<int, int> pii;


//adjacency matrix를 이용하면 좋을 것 같다는 생각. 순서를 찾는 것이니까, 그래프라고 생각해서 이어져 있는지 확인하면 될 것 같다라는 생각.
//결국 플로이드 와샬

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