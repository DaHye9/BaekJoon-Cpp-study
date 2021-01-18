#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>
#include <stack>
#include <map>
#include <iostream>
#include <set>

typedef long long ll;
#define pii pair<int, int>

long long INF = 1e18;
using namespace std;

int t, n, tree[75000*5];
pii loca[75000];

void update(int curr, int s, int e, int ds, int de) {
	if (ds <= s && e <= de) {
		tree[curr]++;
	}
	else if (e<ds || s>de) {
		return;
	}
	else {
		update(curr * 2, s, (s + e) / 2, ds, de);
		update(curr * 2 + 1, (s + e) / 2 + 1, e, ds, de);
		tree[curr] = tree[curr * 2] + tree[curr * 2 + 1];
	}
}

int find(int curr, int s, int e, int ds, int de) {
	if (ds <= s && e <= de) {
		return tree[curr];
	}
	else if (e<ds || s>de) {
		return 0;
	}
	else {
		return find(curr * 2, s, (s + e) / 2, ds, de) + find(curr * 2 + 1, (s + e) / 2 + 1, e, ds, de);
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		memset(tree, 0, sizeof(tree));
		for (int i = 0; i < n; i++) {
			int x, y;
			scanf("%d %d", &x, &y);
			loca[i].first = x, loca[i].second = y;
		}

		sort(loca, loca + n, [](pii& a, pii& b) {return a.second < b.second; });

		int newy[75000], y = 0;
		for (int i = 0; i < n - 1; i++) {
			newy[i] = y;
			if (loca[i].second != loca[i + 1].second)y++;
		}
		newy[n - 1] = y;
		for (int i = 0; i < n; i++) {
			loca[i].second = newy[i];
		}
		sort(loca, loca + n, [](pii& a, pii& b) {
			if (a.first == b.first)return a.second > b.second;
			return a.first < b.first;
			});

		ll ans = 0;
		for (int i = 0; i < n; i++) {
			int y = loca[i].second;
			ans += find(1, 0, n - 1, y, 1000000000);
			update(1, 0, n - 1, y, y);
		}

		printf("%ld\n", ans);
	}
}