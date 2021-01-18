#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cstring>
#include <queue>
#define pii pair<int,int>
#define MAX 30000000
using namespace std;

struct cmp {
	bool operator()(pair<double, int> a, pair<double, int> b) {
		return a.first > b.first;
	}
};
double x, y, xx, yy;
int n;
double d[103][2], visited[101];
double dij[103];
priority_queue <pair<double,int>, vector<pair<double,int>>, cmp> q;

double dis(int a, int b) {
	return sqrt(pow(d[a][0] - d[b][0], 2) + pow(d[a][1] - d[b][1], 2));
}

int main() {
	scanf("%lf %lf %lf %lf", &x, &y, &xx, &yy);
	scanf("%d", &n);

	int k = n + 1; d[k][0] = xx; d[k][1] = yy; d[0][0] = x; d[0][1] = y;

	for (int i = 1; i <= n; i++) {
		scanf("%lf %lf", &d[i][0], &d[i][1]);
		dij[i] = dis(0, i);
		q.push({ dij[i], i });
	}
	dij[k] = dis(0, k); q.push({ dij[k],k });
	visited[0] = 1;
	q.push({ dij[k], k });

	while (!q.empty()) {
		while (visited[q.top().second]) q.pop();
		int temp = q.top().second;
		//printf("start: %d %lf\n", temp, q.top().first);
		if (temp == k) break;
		q.pop(); visited[temp] = 1;
		for (int i = 1; i <= n; i++) {
			if (!visited[i]) {
				double tempd = dis(i, temp);
				dij[i] = min(dij[i], dij[temp] + tempd);
				dij[i] = min(dij[i], dij[temp] + abs(tempd - 50) + 10);
				q.push({ dij[i],i });
				//printf("%d %lf\n", i, dij[i]);
			}
			double tempd = dis(k, temp);
			dij[k] = min(dij[k], dij[temp] + tempd);
			dij[k] = min(dij[k], dij[temp] + abs(tempd - 50) + 10);
			q.push({ dij[k],k });
		}
	}
	printf("%lf", dij[k] / 5);
}