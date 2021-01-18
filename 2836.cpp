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

int n, m, cnt;
ll ans;
vector <pii> v;
map <int, int> mp;


int main() {
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		if (a > b) {
			v.push_back({ a,-1 });
			v.push_back({ b,1 });
		}
	}
	sort(v.begin(), v.end());


	int s=0;
	bool flag = true;
	for (int i = 0; i < v.size(); i++) {
		//printf("%d\n", s);
		int now = v[i].first;
		if (flag)s = now;
		flag = false;
		cnt += v[i].second;
		if (cnt == 0) {
			ans += (now - s) * 2;
			flag = true;
		}
	}

	printf("%ld", ans + m);
}