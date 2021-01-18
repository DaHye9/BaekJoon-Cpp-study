#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n;
vector <pii> ran[3];
int tree[1111111];
int ans;

int compare(pii a, pii b) {
	return a.first > b.first;
}

int update(int s, int e, int node, int index, int val) {
	if (node<s || node>e)return 555555;
	if (s == e) {
		tree[index] = val;
		return val;
	}
	int mid = (s + e) / 2;
	tree[index] = min(update(s, mid, node, index * 2, val), min(tree[index], update(mid + 1, e, node, index * 2 + 1, val)));
	return tree[index];
}

int f(int s, int e, int ns, int ne, int node, int index) {
	if (s > ne || e < ns) return 555555;
	if (s <= ns && ne <= e) return tree[index];
	int mid = (ns + ne) / 2;
	return min(f(s, e, ns, mid, node, index * 2), f(s, e, mid + 1, ne, node, index * 2 + 1));
	
}

int main() {
	scanf("%d", &n);
	for (int i = 0; i < 1111111; i++)tree[i] = 555555;
	int temp;
	for (int i = 0; i < 3; i++) {
		for (int k = 1; k <= n; k++) {
			scanf("%d", &temp);
			ran[i].push_back({ temp,k });//인덱스,등수
		}
	}

	sort(ran[1].begin(), ran[1].end(), compare);
	sort(ran[2].begin(), ran[2].end(), compare);
	//인덱스순으로 정렬
	for (int i = 0; i < n; i++) {
		temp = ran[0][n - i - 1].first;//가장 낮은 등수애의 인덱스
		int node = ran[1][temp].second;//그 인덱스의 등수
		int val = ran[2][temp].second;
		update(1, n, node, 1, val);
		if (f(1, node, 1, n, node, 1) == n) {
			printf("%d", n);
			ans++;
		}
	}

	printf("%d", ans);
}