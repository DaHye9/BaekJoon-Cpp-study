#include <cstdio>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n;
long long citizen[10001];
long long dp[2][10001];
int visited[10001]; 
vector <int> adj[10001];

long long f(int node, int state) {
	long long result = 0;
	if (dp[state][node] != 0) return dp[state][node];
	visited[node] = 1;
	for (int i = 0; i < adj[node].size(); i++) {
		if (!visited[adj[node][i]]) {
			if (state) {//node가 우수마을
				result += f(adj[node][i], 0);//다음꺼는 우수면 안됨
			}
			else {//node가 우수마을이 아니면
				result += max(f(adj[node][i], 0), f(adj[node][i], 1) + citizen[adj[node][i]]);//다음꺼는 우수거나 우수 아니거나
			}
		}
	}
	//printf("%d %d\n", node, result);
	dp[state][node] = result;
	visited[node] = 0;
	return result;
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &citizen[i]);
	}
	int a, b;
	for (int i = 1; i < n; i++) {
		scanf("%d %d", &a, &b);
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	printf("%lld", max(f(1,1)+citizen[1],f(1,0)));
}