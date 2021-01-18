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

int s, e, visit[2001][2001];
int ans;

int gcd(int a, int b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	scanf("%d %d", &s, &e);

	for (int i = s; i <= e; i++) {
		for (int j = 0; j < i; j++) {
			int a = gcd(i, j);
			if (visit[i / a][j / a] == 0) {
				visit[i / a][j / a] = 1;
				ans++;
			}
		}
	}
	printf("%d", ans);
}