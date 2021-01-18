#include <cstdio>
#include <algorithm>

using namespace std;

long long k;
long long dp[130];
long long temp[130];

void f(int n) {
    if (dp[n] != 0) {
        f(n + 1);
        return;
    }
    if (n == 93) return;
    dp[n] = temp[n - 2];
    temp[n] = temp[n - 1] + dp[n];
    f(n + 1);
    return;
}

int main() {
    scanf("%lld", &k);

    dp[0] = 1;
    dp[1] = 1;
    dp[2] = 1;
    temp[0] = 1;
    temp[1] = 2;
    temp[2] = 3;
    f(0);
    int start = 90;
    while (temp[start] > k)start--;
    for (; start >= 0; start--) {
        if (temp[start] <= k) {
            k -= temp[start];
            printf("1");
        }
        else printf("0");

        //printf("%d %lld\n\n", start, k);
    }
}
