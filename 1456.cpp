#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <cstring>
#define pii pair<int, int>
#define MAX 10000001
using namespace std;

long long a, b;
int isprime[MAX];
int ans;

int main() {
	scanf("%lld %lld", &a, &b);
	memset(isprime, 1, sizeof(isprime));
	for (int i = 4; i < MAX; i += 2) {
		isprime[i] = 0;
	}
	long long temp = 2;
	while (temp <= b / 2) {
		if (temp * 2 >= a) {
			ans++;
		}
		temp = temp * 2;
	}
	for (int i = 3; i < MAX; i += 2) {
		if (!isprime[i]) continue;
		unsigned long long temp = i;
		if (temp > b) break;
		while (temp <= b / i) {
			if (temp * i >= a) {
				ans++;
			}
			temp *= i;
		}
		for (long long j = (long long) i * i; j < MAX; j += (long long) i * 2) isprime[j] = 0;
	}
	printf("%d", ans);
}