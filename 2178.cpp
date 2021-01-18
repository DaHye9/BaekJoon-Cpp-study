#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>

int n, m;
int arr[101][101];
int visited[101][101];
int cnt[101][101];
queue <pii> q;

void bfs() {
	q.push(pii(1, 1));
	visited[1][1] = 1;
	cnt[1][1] = 1;
	while (!q.empty()) {
		pii temp = q.front();
		if (temp == pii(n, m)) break;
		q.pop();
		//printf("%d %d %d\n", temp.first, temp.second, cnt[temp.first][temp.second]);
		if (temp.first >= 2 && visited[temp.first - 1][temp.second] == 0 && arr[temp.first - 1][temp.second] ==1) {
			visited[temp.first - 1][temp.second] = 1;
			q.push(pii(temp.first - 1, temp.second));
			cnt[temp.first - 1][temp.second] = cnt[temp.first][temp.second] + 1;
		}
		if (temp.first <= n - 1 && visited[temp.first + 1][temp.second] == 0 && arr[temp.first + 1][temp.second] == 1) {
			visited[temp.first + 1][temp.second] = 1;
			q.push(pii(temp.first + 1, temp.second));
			cnt[temp.first + 1][temp.second] = cnt[temp.first][temp.second] + 1;
		}
		if (temp.second >= 2 && visited[temp.first][temp.second - 1] == 0 && arr[temp.first][temp.second - 1] == 1) {
			visited[temp.first][temp.second - 1] = 1;
			q.push(pii(temp.first, temp.second - 1));
			cnt[temp.first][temp.second - 1] = cnt[temp.first][temp.second] + 1;
		}
		if (temp.second <= m - 1 && visited[temp.first][temp.second + 1] == 0 && arr[temp.first][temp.second + 1] == 1) {
			visited[temp.first][temp.second + 1] = 1;
			q.push(pii(temp.first, temp.second + 1));
			cnt[temp.first][temp.second + 1] = cnt[temp.first][temp.second] + 1;
		}
	}
}

int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%1d", &arr[i][j]);
		}
	}

	bfs();

	printf("%d", cnt[n][m]);
}