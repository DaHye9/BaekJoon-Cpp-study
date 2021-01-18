#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n;
long long ans = 1;
long long tree[1 << 21];
int numtree[1 << 21];
int num;

void update(int s, int e, int index, int t, int node){
	if (s > index || e < index) return;
	tree[node] += t;
	numtree[node] += 1;
	if (s == e) return;

	int mid = (s + e) / 2;
	update(s, mid, index, t, node * 2);
	update(mid + 1, e, index, t, node * 2 + 1);
}
long long f(int s, int e, int ns, int ne, int index) {
	if (s > ne || e < ns) return 0;
	if (s <= ns && ne <= e) {
		return tree[index];
	}
	int mid = (ns + ne) / 2;
	return f(s, e, ns, mid, index * 2) + f(s, e, mid + 1, ne, index * 2 + 1);
}
int numf(int s, int e, int ns, int ne, int index) {
	if (s > ne || e < ns) return 0;
	if (s <= ns && ne <= e) {
		return numtree[index];
	}
	int mid = (ns + ne) / 2;
	return numf(s, e, ns, mid, index * 2) + numf(s, e, mid + 1, ne, index * 2 + 1);
}

int main() {
	scanf("%d", &n);
	long long temp;
	long long anst = 1;

	for (int i = 0; i < n; i++) {
		scanf("%lld", &temp);
		//printf("%d %d\n", -f(0, temp, 0, 200000, 1), temp * numf(0, temp, 0, 200000, 1));
		anst = (anst + (-f(0, temp, 0, 200000, 1) + temp * numf(0, temp, 0, 200000, 1))) % 1000000007;
		//printf("anst = %d\n", anst);

		anst = (anst + f(temp + 1, 200000, 0, 200000, 1) - temp * numf(temp + 1, 200000, 0, 200000, 1)) % 1000000007;
		//printf("anst = %d\n", anst);
		
		update(0, 200000, temp, temp, 1);
		ans *= anst;
		ans = ans % 1000000007;
		//printf("ans : %d\n", ans);
		anst = 0;
	}

	printf("%lld", ans);
}