#include <algorithm>
#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
#define pii pair<int,int>
int cnt[101];
int n, first, second, m;
vector <pii> relation;
int visited[101];
queue <int> q;

void bfs(int a) {
	visited[a] = 1;
	q.push(a);
	int temp;
	while (!q.empty()) {
		temp = q.front();
		q.pop();
		for (int i = 0; i < 2 * m; i++) {
			if (relation[i].first == temp && visited[relation[i].second] == 0) {
				visited[relation[i].second] = 1;
				cnt[relation[i].second] = cnt[temp] + 1;
				q.push(relation[i].second);
			}
		}
	}
}

int main() {
	scanf("%d %d %d %d", &n, &first, &second, &m);
	for (int i = 0; i < m; i++) {
		int x, y;
		scanf("%d %d", &x, &y);
		relation.push_back(pii(x, y));
		relation.push_back(pii(y, x));
	}
	
	bfs(first);
	if (cnt[second] != 0)
		printf("%d", cnt[second]);
	else printf("-1");
}