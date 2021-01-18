#include <cstdio>
#include <algorithm>
#include <string.h>

using namespace std;

int n;
double movep[4];
int visited[30][30];
int cnt = 0;
double ans = 0;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { 1,-1,0,0 };

void f(int x, int y, int cnt, double per) {
	if (visited[x][y]) return;
	if (cnt == n) {
		ans += per;
		//printf("%lf\n\n", ans);
		return;
	}
	//printf("%d %d %d %lf %lf\n", x, y, cnt, per, ans);

	visited[x][y] = 1;

	/*for (int i = 0; i < 30; i++) {
		for (int j = 0; j < 30; j++) {
			printf("%d", visited[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	*/

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		f(nx, ny, cnt + 1, per * movep[i]);
	}

	visited[x][y] = 0;

}

int main() {
	scanf("%d %lf %lf %lf %lf", &n, &movep[0], &movep[1], &movep[2], &movep[3]);
	for (int i = 0; i < 4; i++) {
		movep[i] = movep[i] / 100;
		//printf("%lf \n", movep[i]);
	}

	f(14, 14, 0, 1);

	printf("%.10lf", ans);
}