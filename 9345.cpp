#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int t;
pii tree[300000];
int n, k, num;

pii update(int ns, int ne, int index, int node, int to) {
	if (node<ns || node>ne)return tree[index];
	if (ns == node && node == ne) {
		return tree[index] = { to,to };
	}
	
	int mid = (ns + ne) / 2;
	pii a = update(ns, mid, index * 2, node, to);
	pii b = update(mid + 1, ne, index * 2 + 1, node, to);
	//printf("4°³ %d %d %d %d", a.first, a.second, b.first, b.second);
	int ma = min(a.first, b.first);
	int mb = max(a.second, b.second);
	//printf("mamb%d %d %d\n",index, ma, mb);
	return tree[index] = { ma,mb };
}

pii check(int s, int e, int ns, int ne, int node) {
	if (ne < s || ns > e) return { 111111,-1 };
	if (s <= ns && ne <= e) return tree[node];
	if (ne != ns) {
		int mid;
		mid = (ne + ns) / 2;
		pii a = check(s, e, ns, mid, node * 2);
		pii b = check(s, e, mid + 1, ne, node * 2 + 1);
		int mi = min(a.first, b.first);
		int ma = max(a.second, b.second);
		return { mi,ma };
	}
}

int main() {
	scanf("%d", &t);
	while (t--) {
		int state, a, b;
		scanf("%d %d", &n, &k);
		for (int i = 0; i < 300000; i++) {
			tree[i] = { 111111,-1 };
		}
		for (int i = 0; i < n; i++) {
			update(0, n - 1, 1, i, i);
		}
		for (int i = 0; i < k; i++) {
			scanf("%d %d %d", &state, &a, &b);
			if (state) {
				pii result=	check(a, b, 0, n - 1, 1);
				//printf("%d %d", result.first, result.second);
				if (result.first == a && result.second == b) printf("YES\n");
				else printf("NO\n");
			}
			else {
				pii toa = check(b, b, 0, n - 1, 1);
				pii tob= check(a, a, 0, n - 1, 1);
				update(0, n - 1, 1, a, toa.first);
				//printf("%d ", toa.first);
				//printf("%d\n", tob.first);
				update(0, n - 1, 1, b, tob.first);
			}
		}
	}
}