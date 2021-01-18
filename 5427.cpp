#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>

int t, w, h;
int visited[1010][1010];
char arr[1010][1010];
int added[2][1111111];
int l = 1;
int x, y, fx, fy;
int p = 0;
vector<pii> v;
queue<pii> fq;
queue<pii> q;

int check(int state, int a, int b) {
	if (state == 1 && visited[a][b] == 0) {
		visited[a][b] = 1;
		q.push({ a,b });
		added[0][l]++;
	}
	else if (state == -2 && visited[a][b] >= 0) {
		visited[a][b] = -2;
		fq.push({ a,b });
		added[1][l]++;
	}

	if (state == 1 && (a == 1 || a == h || b == 1 || b == w) && visited[a][b] == 1) {
		fx = a;
		fy = b;
		return 1;
	}
	return 0;
}

void bfs() {
	int state = 0;
	while(!q.empty()) {
		
		for (int i = 0; i < added[1][l - 1]; i++) {
			pii temp = fq.front();
			check(-2, temp.first - 1, temp.second);
			check(-2, temp.first + 1, temp.second);
			check(-2, temp.first, temp.second - 1);
			check(-2, temp.first, temp.second + 1);
			fq.pop();
		}for (int i = 0; i < added[0][l - 1]; i++) {
			pii temp = q.front();
			//printf("%d %d\n", temp.first, temp.second);
			state = (check(1, temp.first - 1, temp.second) || check(1, temp.first + 1, temp.second) || check(1, temp.first, temp.second - 1) || check(1, temp.first, temp.second + 1));
			if (state == 1) break;
			q.pop();
		}
		//printf("%d", state);
		if (state == 1)break;
		if (added[0][l] == 0) {
			p = 1;
			break;
		}
		l++;
	}
}

void ready(int a, int b) {
	//printf("%d %d", a, b);
	q.push({ a,b });
	visited[a][b] = 1;

	for (int i = 0; i < v.size(); i++) {
		fq.push({ v[i].first, v[i].second });
	}
	added[1][0] = v.size();
	added[0][0] = 1;

	bfs();
	
}



int main() {
	scanf("%d", &t);
	for (int i = 1; i <= t; i++) {
		scanf("%d %d", &w, &h);
		for (int j = 1; j <= h; j++) {
			scanf("%s", &arr[j][1]);
			for (int k = 1; k <= w; k++) {
				if (arr[j][k] == '#') visited[j][k] = -1;
				else if (arr[j][k] == '*') {
					v.push_back({ j,k });
					visited[j][k] = -2;
				}
				else if (arr[j][k] == '@') {
					visited[j][k] = 1;
					x = j; y = k;
				}
			}
		}

		if (x == h || x == 1 || y == w || y == 1) {
			printf("1\n");
			v.clear();
			continue;
		}

		for (int j = 0; j <= h + 1; j++) {
			arr[j][0] = arr[j][w + 1] = '#';
			visited[j][0] = visited[j][w + 1] = -1;
		}
		for (int j = 0; j <= w + 1; j++) {
			arr[0][j] = arr[h + 1][j] = '#';
			visited[0][j] = visited[h + 1][j] = -1;
		}

		ready(x, y);

		p == 1 ? printf("IMPOSSIBLE\n") : printf("%d\n", l + 1);

		for (int j = 0; j <= h + 1; j++) {
			for (int k = 0; k <= w + 1; k++) {
				//printf("%d", visited[j][k]);
				visited[j][k] = 0;
			}
			//printf("\n");
		}

		for (int j = 0; j <= l; j++) {
			added[0][j] = 0;
			added[1][j] = 0;
		}
		p = 0;
		l = 1;
		v.clear();

		while (!q.empty()) q.pop();
		while (!fq.empty()) fq.pop();
	}
}