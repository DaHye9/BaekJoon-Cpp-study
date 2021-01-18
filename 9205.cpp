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
// ����ư �Ÿ��� 1000 �����̸� �� �� �� �ִ�. bfs�� dfs�� �÷��̵� �ͼ� ��� ����.
// �÷��̵� �ͼ��� ���� ��������, ó������ �׳� bfs�� ���ϰڴµ�? ��� ������ �� ����.

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