#include <cstdio>
#include <algorithm>
#include <queue>
#include <vector>
#include <math.h>
#include <utility>
#include <map>
#define pii pair <int,int>
#define ll long long
long long INF = 1e18;
using namespace std;

typedef struct v {
	long long x, y, z;
	int index;
}v;

int n;
v in[100001];
int parent[100001];
vector <pair<pii, long long>> edge;
long long ans = 0;

int find(long long a) {
	//printf("%lld\n", a);
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int merge(long long a, long long b) {
	a = find(a); b = find(b);
	if (a == b) return 0;

		parent[a] += parent[b];
		parent[b] = a;
	
	return 1;
}

bool compare(pair<pii, long long> a, pair<pii, long long> b) {
	return a.second < b.second;
}

bool comparex(v a, v b) {
	return a.x < b.x;
}

bool comparey(v a, v b) {
	return a.y < b.y;
}

bool comparez(v a, v b) {
	return a.z < b.z;
}

int main() {
	scanf("%d", &n);
	
	for (int i = 0; i < n; i++) {
		long long x, y, z;
		scanf("%lld %lld %lld", &x, &y, &z);
		in[i].x = x; in[i].y = y; in[i].z = z; in[i].index = i;
		parent[i] = -1;
	}
	
	sort(in, in + n, comparex);
	
	for (int i = 0; i < n - 1; i++) {
		edge.push_back({ {in[i].index,in[i + 1].index},abs(in[i].x - in[i + 1].x )});
	}
	sort(in, in + n, comparey);

	for (int i = 0; i < n - 1; i++) {
		edge.push_back({ {in[i].index,in[i + 1].index},abs(in[i].y - in[i + 1].y )});
	}
	sort(in, in + n, comparez);

	for (int i = 0; i < n - 1; i++) {
		edge.push_back({ {in[i].index,in[i + 1].index},abs(in[i].z - in[i + 1].z )});
	}
	sort(edge.begin(), edge.end(), compare);

	int cnt = 0;
	int index = 0;
	while (cnt < n - 1) {
		int s = edge[index].first.first, e = edge[index].first.second, k = edge[index].second;
		if (merge(s, e)) {
			cnt++;
			ans += k;
		}
			index++;
	}

	printf("%lld", ans);
}