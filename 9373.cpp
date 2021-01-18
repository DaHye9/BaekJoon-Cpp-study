#include <iostream>
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

typedef tuple<double, int, int> Edge;

long long INF = 1e18;
using namespace std;

int t, n, w, parent[1003];
double ans;
Edge input[1003];

double distance(Edge a, Edge b) {
	return sqrt(pow(get<1>(a) - get<1>(b), 2) + pow(get<2>(a) - get<2>(b), 2));
}

int find(int a) {
	if (parent[a] < 0) return a;
	return parent[a] = find(parent[a]);
}

int merge(int a, int b) {
	a = find(a); b = find(b);
	if (a == b) return 0;

	if (parent[a] < parent[b]) {
		parent[a] += parent[b];
		parent[b] = a;
	}
	else {
		parent[b] += parent[a];
		parent[a] = b;
	}
	return 1;
}

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d %d", &w, &n);
		for (int k = 1; k <= n; k++) {
			int a, b; double c;
			scanf("%d %d %lf", &a, &b, &c);
			input[k] = Edge(c, a, b);
			parent[k] = -1;
		}

		parent[0] = parent[n + 1] = -1;
		vector <Edge> d;
		d.push_back(Edge(w, 0, n + 1));

		for (int k = 1; k <= n; k++) {
			d.push_back(Edge(max(0.0, get<1>(input[k]) - get<0>(input[k])), 0, k));
			d.push_back(Edge(max(0.0, w-(get<1>(input[k]) + get<0>(input[k]))), k, n + 1));
			for (int j = k + 1; j <= n; j++) {
				d.push_back(Edge(max(0.0, distance(input[k], input[j]) - get<0>(input[k]) - get<0>(input[j])), k, j));
			}
		}

		sort(d.begin(), d.end());

		for (int k = 0; k < d.size(); k++) {
			//printf("%d %d\n", get<1>(d[k]), get<2>(d[k]));
			if (merge(get<1>(d[k]), get<2>(d[k]))) {
				if (find(0) == find(n + 1)) {
					ans = (double) (get<0>(d[k])) / 2;
					ans == 0 ? printf("0\n") : printf("%lf\n", ans);
					break;
				}
			}
		}
	}

	return 0;
}