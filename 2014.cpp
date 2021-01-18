#include <cstdio>
#include <vector>
#include <queue>
using namespace std;

int k, n, prime[101];
priority_queue <long long, vector<long long>, greater <long long>> q;
int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < k; i++) {
		scanf("%d", &prime[i]);
		q.push(prime[i]);
	}
	long long temp;
	while (n--) {
		temp = q.top();
		for (int j = 0; j < k; j++) {
			q.push(temp * prime[j]);
			if (temp % prime[j] == 0) break; //기울기가 -1인 직선 아래것만 곱하면 됨
			//printf("%lld\n", temp * prime[j]);
		}
		q.pop();
	}
	
	printf("%lld", temp);
}
