#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int r, c;
int result = 0;
int used[26];
int visited[20][20];
char input[20][20];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1,0,0 };

void backtracking(int x, int y, int time) {
	visited[x][y] = 1;
	used[input[x][y] - 'A'] = 1;
	result = max(time, result);

	//printf("%d %d\n", x, y);

	for (int i = 0; i < 4; i++) {
		int posx = x + dx[i];
		int posy = y + dy[i];
		if (posx<0 || posy<0 || posx>=r || posy>=c) continue;
		if (visited[posx][posy] == 0 && used[input[posx][posy] - 'A'] == 0) {
			backtracking(posx, posy, time + 1);
		}
	}

	visited[x][y] = 0;
	used[input[x][y] - 'A'] = 0;
}

int main() {
	scanf("%d %d", &r, &c);

	for (int i = 0; i < r; i++) {
		scanf("%s", &input[i][0]);
	}

	backtracking(0, 0, 1);

	printf("%d", result);
}