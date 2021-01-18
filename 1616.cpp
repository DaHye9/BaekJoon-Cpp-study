#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>
#include <unordered_map>

using namespace std;

#define pii pair <int,int>
#define ll long long
#define MAX 5000002

long long INF = 1e18;
using namespace std;

int k, m, adjin[MAX], adjout[MAX];

int main() {
	scanf("%d %d", &k, &m);

	if (m == 1) {
		for (int i = 0; i < k; i++)
			printf("%d ", i);
		return 0;
	}

	int total = pow(k, m); int totalm1 = total / k;
	int degree[MAX] = { 0, };
	for (int i = 0; i < totalm1; i++) {
		adjin[i] = adjout[i] = i * k;
	}
	for (int i = 0; i < totalm1; i++) {
		for (int j = 0; j < k; j++) {

		}
	}
}