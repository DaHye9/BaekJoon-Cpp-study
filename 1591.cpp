#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>
#include <map>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int n, m, indegree[2001], outdegree[2001];
map <vector<int>, int> m;

int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n - m + 1; i++) {
		vector<int> temp;
		for (int j = 0; j < m; j++) {
			scanf("%d", &temp[j]);
		}
	}
}