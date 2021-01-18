#include <cstdio>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n;
int start;
int ans = -1;
int visited[10001];
vector <pii> tree[10001];

void f(int node, int weight) {
	if (visited[node]) return;
	visited[node] = 1;
	
	if (weight > ans) {
		ans = weight;
		start = node;
	}
		//printf("%d\n", max);
	for (int i = 0; i < tree[node].size(); i++) {
		f(tree[node][i].first, weight + tree[node][i].second);
	}
	visited[node] = 0;
}

int main() {
	scanf("%d", &n);
	int parent, child, weight;
	for (int i = 0; i < n - 1; i++) {
		scanf("%d %d %d", &parent, &child, &weight);
		tree[parent].push_back({ child,weight });
		tree[child].push_back({ parent,weight });
	}

	f(1, 0);
	ans = -1;
	f(start, 0);

	printf("%d", ans);
}