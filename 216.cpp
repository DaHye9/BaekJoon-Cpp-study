#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <cstring>
#define pii pair<int, int>
#define ll long long
using namespace std;

ll n, x[10001], y[10001];
ll result;

ll sq(ll x1, ll y1, ll x2, ll y2) {
	return x1 * y2 - x2 * y1;
}

int main() {
	scanf("%lld", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld %lld", &x[i], &y[i]);
	}

	for (int i = 1; i < n - 1; i++) {
		ll x1 = x[i] - x[0];
		ll y1 = y[i] - y[0];
		ll x2 = x[i + 1] - x[0];
		ll y2 = y[i + 1] - y[0];
		result += sq(x1, y1, x2, y2);
	}

	printf("%.1lf", abs(result/2.0));
}