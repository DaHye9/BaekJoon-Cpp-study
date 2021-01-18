#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

map <long long, long long> m;
long long n, p, q;

long long f(long long a) {
	if (m.count(a)) return m[a];
	else return m[a] = f(a / p) + f(a / q);
}

int main() {
	scanf("%lld %lld %lld", &n, &p, &q);
	int pointer = 0;
	m[0] = 1;
	f(n);
	printf("%lld", m[n]);
}