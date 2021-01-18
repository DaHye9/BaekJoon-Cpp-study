#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>

int t, l;
pii x;
pii y;
int visited[301][301];
int cnt[301][301];
queue <pii> q;

void bfs(int a, int b) {
	q.push(pii(a, b));
	visited[a][b] = 1;
	cnt[a][b] = 0;
	while (!q.empty()) {
		pii temp = q.front();
		q.pop();
		int tf = temp.first;
		int ts = temp.second;
		if (pii(tf, ts) == y) {
			break;
		}
		if (tf - 1 >= 0) {
			if (ts - 2 >= 0 && visited[tf -1][ts-2] == 0) {
				q.push(pii(tf - 1, ts - 2));
				visited[tf - 1][ts - 2] = 1;
				cnt[tf - 1][ts - 2] = cnt[tf][ts] + 1;
			}
			if (ts + 2 < l && visited[tf - 1][ts + 2] == 0) {
				q.push(pii(tf - 1, ts + 2));
				visited[tf - 1][ts + 2] = 1;
				cnt[tf - 1][ts + 2] = cnt[tf][ts] + 1;
			}
		}
		if (tf - 2 >= 0) {
			if (ts - 1 >= 0 && visited[tf - 2][ts - 1] == 0) {
				q.push(pii(tf - 2, ts - 1));
				visited[tf - 2][ts - 1] = 1;
				cnt[tf - 2][ts - 1] = cnt[tf][ts] + 1;
			}
			if (ts + 1 < l && visited[tf - 2][ts + 1] == 0) {
				q.push(pii(tf - 2, ts + 1));
				visited[tf - 2][ts + 1] = 1;
				cnt[tf - 2][ts + 1] = cnt[tf][ts] + 1;
			}
		}
		if (tf + 1 < l) {
			if (ts - 2 >= 0 && visited[tf + 1][ts - 2] == 0) {
				q.push(pii(tf + 1, ts - 2));
				visited[tf + 1][ts - 2] = 1;
				cnt[tf + 1][ts - 2] = cnt[tf][ts] + 1;
			}
			if (ts + 2 < l && visited[tf + 1][ts + 2] == 0) {
				q.push(pii(tf + 1, ts + 2));
				visited[tf + 1][ts + 2] = 1;
				cnt[tf + 1][ts + 2] = cnt[tf][ts] + 1;
			}
		}
		if (tf + 2 < l) {
			if (ts - 1 >= 0 && visited[tf + 2][ts - 1] == 0) {
				q.push(pii(tf + 2, ts - 1));
				visited[tf + 2][ts - 1] = 1;
				cnt[tf + 2][ts - 1] = cnt[tf][ts] + 1;
			}
			if (ts + 1 < l && visited[tf + 2][ts + 1] == 0) {
				q.push(pii(tf + 2, ts + 1));
				visited[tf + 2][ts + 1] = 1;
				cnt[tf + 2][ts + 1] = cnt[tf][ts] + 1;
			}
		}
	}
}
int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &l);
		scanf("%d %d", &x.first, &x.second);
		scanf("%d %d", &y.first, &y.second);

		bfs(x.first, x.second);

		printf("%d\n", cnt[y.first][y.second]);

		for (int j = 0; j < l; j++) {
			for (int k = 0; k < l; k++) {
				visited[j][k] = 0;
			}
		}

		while (!q.empty()) {
			q.pop();
		}
	}
}