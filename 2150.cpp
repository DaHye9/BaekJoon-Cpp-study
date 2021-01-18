#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int v, e, cnt, dfsn[10001], sccnum, parent[10001];
vector<int> adj[10001];
int visit[10001];
stack<int> s;
vector<vector<int>>scc;

int dfs(int curr) {
	dfsn[curr] = ++cnt;
	s.push(curr);

	int result = dfsn[curr];
	for (int next : adj[curr]) {
		if (dfsn[next] == 0)result = min(result, dfs(next)); //���� �湮 X
		else if (!visit[next])result = min(result, dfsn[next]); //�湮�� ������ ���� scc�� �ƴ�
	}

	if (result == dfsn[curr]) {//�ڽ��� �ڽĵ��� ���� ������ ���� ���� ������ �ڽ��� ��� scc�� ����
		vector<int> currscc;
		while (1) {
			int t = s.top();
			s.pop();
			currscc.push_back(t);
			visit[t] = 1;
			parent[t] = sccnum;
			if (t == curr)break; //�ڽ��� ���� ������ ��
		}
		sort(currscc.begin(), currscc.end());

		scc.push_back(currscc);
		sccnum++;
	}
	return result;
}

int main() {
	scanf("%d %d", &v, &e);
	for (int i = 0; i < e; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		adj[a - 1].push_back(b - 1);
	}

	for (int i = 0; i < v; i++) {
		if (dfsn[i] == 0)dfs(i);
	}
	sort(scc.begin(), scc.end());

	printf("%d\n", sccnum);
	for (auto& currscc : scc) {
		for (int curr : currscc) printf("%d ", curr + 1);
		puts("-1");
	}
}