#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>

int r, c;
char arr[510][510];
int visited[510][510];
int sx, sy;
int time = 1;
queue<pii> water;

vector <pii> waterlist;
int dx[] = { 1, -1, 0, 0 };
int dy[] = { 0, 0, 1, -1 };

bool bfs() {
	bool state = false;
	queue<pii> q;

	q.push({ sx, sy });

	while (!q.empty()) {
		int wcnt = water.size();
		int qcnt = q.size();
		for (int i = 0; i < wcnt; i++) {
			pii temp = water.front();
			water.pop();
			for (int j = 0; j < 4; j++) {
				int px = temp.first + dx[j];
				int py = temp.second + dy[j];
				if (arr[px][py] == '.' || arr[px][py] == 'V' || arr[px][py] == 'S') {
					water.push({ px,py });
					arr[px][py] = '*';
				}
			}
		}
		for (int i = 0; i < qcnt; i++) {
			pii temp = q.front();
			q.pop();
			for (int j = 0; j < 4; j++) {
				int px = temp.first + dx[j];
				int py = temp.second + dy[j];
				if (arr[px][py] == '.') {
					q.push({ px,py });
					arr[px][py] = 'V';
				}
				else if (arr[px][py] == 'D') {
					return true;
				}
			}
		}
		/*for (int j = 0; j <= r + 1; j++) {
			for (int k = 0; k <= r + 1; k++) {
				printf("%c", arr[j][k]);
			}
			printf("\n");
		}*/
		time++;
	}
	return false;
}

int main() {
	scanf("%d %d", &r, &c);
	for (int i = 1; i <= r; i++) {
		scanf("%s", &arr[i][1]);
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] == 'S') {
				sx = i; sy = j;
			}
			else if (arr[i][j] == '*') {
				water.push({ i,j });
			}
		}
	}
	
	bool state = bfs(); 
	state == true ? printf("%d", time) : printf("KAKTUS");
}