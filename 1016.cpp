#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#include <cstring>
#define pii pair<int, int>
#define MAX 1000001

using namespace std;
long long a, b;
int result[1000001];
int isprime[1000001];
vector <long long> prime;
int ans, maxn;

int main() {
	scanf("%lld %lld", &a, &b);
	long long k;
	for (k = 2; (long long)k * k < b; k++);
	maxn = k;
	memset(isprime, 1, sizeof(isprime));
	prime.push_back(2);

	for (int i = 4; i <= maxn; i += 2)isprime[i] = 0;
	for (int i = 3; i <= maxn; i += 2) {
		prime.push_back(i);
		for (long long j = (long long)i * i; j <= 1000000; j += (long long)2 * i) {
			isprime[j] = 0;
		}
	}
	for (int i = 0; i < prime.size(); i++) {
		int th = prime[i];
		long long now = (long long) th * th;
		if (now > b)break;
		long long temp = a / now;
		temp = temp * now;
		if (temp < a) temp += now;
		while (temp <= b) {
			//printf("%lld %lld\n", temp, b);
			result[temp - a] = 1;
			temp += now;
		}
	}
	for (int i = 0; i <= b - a; i++) {
		if (result[i] == 0) ans++;
	}

	printf("%d", ans);
}