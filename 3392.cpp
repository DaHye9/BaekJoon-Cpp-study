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

int n, tree[30001 * 5], cnt[30001 * 5], ans;
vector <pair<pii, pii>> loca;

void update(int stat, int curr, int s, int e, int ds, int de) {
	if (ds <= s && e <= de) { //포함
		if (stat == 0) {
			cnt[curr]++;
		}
		else cnt[curr]--;

		if (cnt[curr]) {
			tree[curr] = e - s + 1;
		}
		else tree[curr] = tree[curr * 2] + tree[curr * 2 + 1];
	}
	else if (ds > e || de < s) { //바깥
		return;
	}
	else { //일부 포함
		int mid = (s + e) / 2;
		update(stat, curr * 2, s, mid, ds, de);
		update(stat, curr * 2 + 1, mid + 1, e, ds, de);

		if (cnt[curr]) {
			tree[curr] = e - s + 1;
		}
		else tree[curr] = tree[curr * 2] + tree[curr * 2 + 1];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int x1, y1, x2, y2;
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2);
		loca.push_back({{ x1,y1 }, { y2,0 }});
		loca.push_back({ { x2,y1 }, { y2,1 } });
	}
	sort(loca.begin(), loca.end(), [](pair<pii, pii> a, pair<pii, pii> b) {return a.first.first < b.first.first; });

	int last = loca[0].first.first;
	for (int i = 0; i < 2 * n; i++) {
		int x1 = loca[i].first.first, y1 = loca[i].first.second, y2 = loca[i].second.first, stat = loca[i].second.second;
		ans += (x1 - last) * tree[1];
		update(stat, 1, 0, 30000, y1 + 1, y2);
		//printf("%d %d %d\n",x1, last, ans);
		last = x1;
	}

	printf("%d", ans);
}