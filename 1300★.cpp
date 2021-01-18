#include <cstdio>
#include <algorithm>
using namespace std;
typedef long long ll;
int n;
ll k;


int main() {
	scanf("%d %lld", &n, &k);
	ll low = 1;
	ll max = k * k;
	ll ans;

	while (low <= max) {
		ll cur = (low + max) / 2;
		ll cnt = 0;
		for (int i = 1; i <= n; i++) {
			cnt += min((cur / i), (ll)n); //개수 구함 : i * j <= cur인 j의 개수 구하기 + n이 1000인경우 n보다 커질 수 있으니 이거 체크 
		}
		if (cnt < k) low = cur + 1;
		else {
			max = cur - 1; // 일케 둘다 + - 1 할 경우에 answer 따로 저장해주어야겠넹
			ans = cur;
		}
	}
	printf("%lld", ans);
}