#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <set>
#define pii pair<int, int>
#define MAX 1000001
using namespace std;

int isnotprime[MAX];
int n;
int arr[101];
vector <int> out;
set <int> used;
int totcnt[MAX];
int ans = 1, cnt;
int prime[MAX];
int primenum = 1;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) scanf("%d", &arr[i]);

	for (int i = 4; i < MAX; i += 2) {
		isnotprime[i] = 1;
	}
	prime[0] = 2;
	for (long long i = 3; i < MAX; i += 2) {
		//printf("%lld\n", i);
		if (isnotprime[i] == 1)continue;
		isnotprime[i] = 0;
		prime[primenum++] = i;
		if (i * i > MAX)continue;
		for (int j = i * i; j < MAX; j += i * 2)isnotprime[j] = 1;
		
	}

	vector <vector<int>> numcnt (101, vector<int>(primenum,0));
	for (int i = 0; i < n; i++) {
		int temp = arr[i];
		for (int j = 0; j < primenum && temp>1; j++) {
			while (temp % prime[j] == 0) {
				numcnt[i][j]++;
				totcnt[j]++;
				temp /= prime[j];
			}
		}
	}
	set<int>::iterator it;
	for (int i = 0; i < primenum;i++) {
		int st = totcnt[i] / n;
		for (int j = 0; j < n; j++) {
		//	printf("%d %d %d\n", i, *it, numcnt[i][*it]);
			if (numcnt[j][i] < st) cnt += st - numcnt[j][i];
		}
		ans *= pow(prime[i], st);
	}

	printf("%d %d", ans, cnt);
}