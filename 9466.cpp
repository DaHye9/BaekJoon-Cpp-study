#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int t, n, arr[100001];
int visited[100001], finished[100001];
int cnt = 0;

void dfs(int a) {
	int temp = arr[a];
	if (visited[a] == 1 && finished[a] == 0) {
		cnt++;
		for (int i = temp; i != a; i = arr[i]) {
			//printf("%d %d\n", i, cnt);
			cnt++;
		}
		//printf("\n");
	}
	else if (visited[a] == 0) {
		visited[a] = 1;
		dfs(temp);
	}
	finished[a] = 1;

}

int main() {
	scanf("%d", &t);

	for (int i = 0; i < t; i++) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &arr[i]);
		}

		for (int i = 1; i <= n; i++) {
			if (visited[i] == 0) dfs(i);
		}
		printf("%d\n", n - cnt);
		cnt = 0;
		for (int i = 0; i <= n; i++) {
			visited[i] = 0;
			finished[i] = 0;
			arr[i] = 0;
		}
	}
}