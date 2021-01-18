#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

struct Edge {
	int to, cnt;
	Edge* dual;
	Edge() :Edge(-1, 0) {}
	Edge(int to1, int cnt1) :to(to1), cnt(cnt1), dual(nullptr) {}
};

int n, degree[1000];
vector<Edge*> adj[1000];
bool visited[1000];

int dfs(int curr) {
	int result = 1;
	visited[curr] = true;
	for (Edge* e : adj[curr]) {
		int next = e->to;
		if (!visited[next])result += dfs(next);
	}
	return result;
}

void Eulerian(int curr) {
	for (Edge* e : adj[curr]) {
		if (e->cnt > 0) {
			e->cnt--;
			e->dual->cnt--;
			Eulerian(e->to);
		}
	}
	printf("%d ", curr + 1);
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			int val;
			scanf("%d", &val);
			if (j > i && val != 0) {
				Edge* e1 = new Edge(j, val), * e2 = new Edge(i, val);
				e1->dual = e2;
				e2->dual = e1;
				adj[i].push_back(e1);
				adj[j].push_back(e2);
				degree[i] += val;
				degree[j] += val;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		if (degree[i] % 2 == 1) {
			puts("-1");
			return 0;
		}
	}

	bool flag = false;
	int start = -1;
	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			int cSize = dfs(i);
			if (cSize > 1) {
				if (flag) {
					puts("-1");
					return 0;
				}
				else {
					start = i;
					flag = true;
				}
			}
		}
	}
	if (start == -1) start = 0;

	Eulerian(start);
}