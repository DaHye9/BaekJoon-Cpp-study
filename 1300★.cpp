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
			cnt += min((cur / i), (ll)n); //���� ���� : i * j <= cur�� j�� ���� ���ϱ� + n�� 1000�ΰ�� n���� Ŀ�� �� ������ �̰� üũ 
		}
		if (cnt < k) low = cur + 1;
		else {
			max = cur - 1; // ���� �Ѵ� + - 1 �� ��쿡 answer ���� �������־�߰ڳ�
			ans = cur;
		}
	}
	printf("%lld", ans);
}