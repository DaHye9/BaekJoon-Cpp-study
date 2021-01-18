#include <cstdio>
#include <algorithm>
#include <vector>
#include <map>
#include <set>
using namespace std;

int k, n, a, input[1001];
set <int> s[9];

void f(int cnt) {
	if (cnt == 9) return;
	for (int i = 1; i < cnt; i++) {
		int a = cnt - i;
		for (set<int>::iterator it = s[i].begin(); it != s[i].end();it++) {
			for (set<int>::iterator it2 = s[a].begin(); it2 != s[a].end();it2++) {
				s[cnt].insert(*it + *it2);
				if (*it > * it2) {
					s[cnt].insert(*it - *it2);
					s[cnt].insert(*it / (*it2));
				}
				else if (*it < *it2) {
					s[cnt].insert(*it2 - *it);
					s[cnt].insert(*it2 / (*it));
				}
				else s[cnt].insert(1);
				s[cnt].insert(*it * (*it2));
			}
		}
	}
	f(cnt + 1);
}

int main() {
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &input[i]);
	}
	for (int i = 1; i <= 8; i++) {
		int temp = 0;
		for (int j = 0; j < i; j++) {
			temp = temp * 10 + k;
		}
		s[i].insert(temp);
	}
	f(1);
	for(int j=0;j<n;j++){
		int i = 1;
		for (i = 1; i <= 8; i++) {
			if (s[i].find(input[j]) != s[i].end()) {
				printf("%d\n", i);
				break;
			}
		}
		if (i == 9)printf("NO\n");
	}
}