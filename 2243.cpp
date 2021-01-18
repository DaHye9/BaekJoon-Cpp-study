#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n;
int tree[3000010];

void update(int s, int e, int ns, int ne, int node, int updatenum, int index) {
	if (ne<s || ns>e)return;
	if (ns <= node && node <= ne) tree[index] = tree[index] + updatenum;
	if (ns == ne) return;
	int mid = (ns + ne) / 2;
	update(s, e, ns, mid, node, updatenum, index * 2);
	update(s, e, mid + 1, ne, node, updatenum, index * 2 + 1);
}

void print(int s, int e, int ns, int ne, int index, int need) {
	if (ne<s || ns>e) return;
	if (ns == ne) {
		tree[index]--;
		printf("%d\n", ns);
		return;
	}
	//printf("%d\n", need);
	int mid = (ns + ne) / 2;
	//printf("%d\n\n", tree[index]);
	if (tree[index * 2] < need)
		print(s, e, mid + 1, ne, index * 2 + 1, need - tree[index * 2]);
	else print(s, e, ns, mid, index * 2, need);
	tree[index]--;
}

int main() {
	scanf("%d", &n);
	int a, b, c;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a);

		if (a == 1) {
			scanf("%d", &b);
			print(1, 1000000, 1, 1000000, 1, b);
		}
		else {
			scanf("%d %d", &b, &c);
			update(1, 1000000, 1, 1000000, b, c, 1);
		}
	}
}