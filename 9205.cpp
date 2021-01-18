#include <iostream>
#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <math.h>

using namespace std;

typedef pair<int, int> pii;

int t, n, visit[103];
pii conv[103];
// 맨해튼 거리가 1000 이하이면 다 갈 수 있다. bfs나 dfs나 플로이드 와샬 모두 가능.
// 플로이드 와샬로 접한 문제지만, 처음에는 그냥 bfs가 편하겠는데? 라는 생각이 든 문제.

int dist(int x1, int y1, int x2, int y2) {
	return abs(x1 - x2) + abs(y1 - y2);
}

void bfs() {
	queue <int> q;
	q.push(0);

	while (!q.empty()) {
		int curr = q.front();
		q.pop();
		visit[curr] = 1;

		for (int i = 1; i < n + 2; i++) {
			if (!visit[i] && dist(conv[curr].first, conv[curr].second, conv[i].first, conv[i].second)<=1000){
				q.push(i);
			}
		}
	}
}


int main() {
	scanf("%d", &t);
	for (int a = 0; a < t; a++) {
		memset(visit, 0, sizeof(visit));
		
		scanf("%d", &n);
		for (int i = 0; i < n + 2; i++) {
			scanf("%d %d", &conv[i].first, &conv[i].second);
		}
		bfs();
		if (visit[n + 1]) printf("happy\n");
		else printf("sad\n");
	}
}