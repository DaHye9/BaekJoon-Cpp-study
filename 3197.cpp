#include <cstdio>
#include <algorithm>
#include <vector>
#include <queue>
#define pii pair<int, int>
using namespace std;

int r, c;
int arr[1510][1510];
queue <int> q;
int parent[10000000];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
int ans = 0;

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

void merge(int x, int y) {
	x = find(x); y = find(y);
	if (x == y) return;
	if (parent[x] < parent[y]) {
		parent[x] += parent[y];
		parent[y] = x;
	}
	else {
		parent[y] += parent[x];
		parent[x] = y;
	}
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 0; i <= r * c; i++) parent[i] = -1;
	char temp[1500]; int groupnum = 1;
	int animal[2];
	int animalcnt = 0;
	for (int i = 0; i < r; i++) {
			scanf("%s", &temp[0]);
			for(int j=0;j<c;j++){
			if (temp[j] == '.' || temp[j] == 'L') {
				if (temp[j] == 'L') animal[animalcnt++] = groupnum;
				arr[i][j] = groupnum++;
				q.push(i * 1500 + j);
				for (int k = 0; k < 4; k++) {
					int tx = i + dx[k]; int ty = j + dy[k];
					if (tx < 0 || ty < 0 || tx >= r || ty >= c || arr[tx][ty] == 0) continue;
					merge(arr[i][j], arr[tx][ty]);
				}
			}
		}
	}
	/*printf("%d %d\n\n", animal[0], animal[1]);
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) printf("%d", arr[i][j]);
		printf("\n");
	}*/
	while (find(animal[0]) != find(animal[1])) {
		int qsize = q.size();
		for (int i = 0; i < qsize; i++) {
			int x = q.front() / 1500; int y = q.front() % 1500;
			q.pop();
			for (int j = 0; j < 4; j++) {
				int tx = x + dx[j]; int ty = y + dy[j];
				if (tx < 0 || ty < 0 || tx >= r || ty >= c || arr[tx][ty] > 0) continue;
				q.push(tx * 1500 + ty);
				arr[tx][ty] = arr[x][y];
				for (int k = 0; k < 4; k++) {
					int txx = tx + dx[k]; int tyy = ty + dy[k];
					if (txx < 0 || tyy < 0 || txx >= r || tyy >= c || arr[txx][tyy] == 0) continue;
					merge(arr[x][y], arr[txx][tyy]);
				}
			}
			/*for (int z = 1; z < 50; z++) {
				printf("%d ", parent[z]);
			}
			printf("\n");*/
		}
		ans++;
	}
	printf("%d", ans);
}