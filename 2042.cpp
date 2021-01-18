#include <iostream>
#include <algorithm>
#include <vector>
#define pii pair<int,int>
using namespace std;

int n, ans;
vector <pii> input;
int tree[4000000];

bool compare(pii a, pii b) {
    if (a.first == b.first) {
        return a.second > b.second;
    }
    return a.first < b.first;
}

void update(int index, int node, int start, int end, int k) {
    if (start > node || node > end) return;

    tree[index] = max(k, tree[index]);

    if (start != end) {
        int mid = (start + end) / 2;
        update(index * 2, node, start, mid, k);
        update(index * 2 + 1, node, mid + 1, end, k);
    }
}

int f(int start, int end, int node, int ns, int ne) {
    if (start > ne || end < ns) return 0;
    if (start <= ns && ne <= end) return tree[node];
    int mid = (ns + ne) / 2;
    return max(f(start, end, node * 2, ns, mid), f(start, end, node * 2 + 1, mid + 1, ne));
}

    int main() {
        scanf("%d", &n);
        int temp = 1;
        for (int i = 0; i < n; i++) {
            scanf("%d", &temp);
            input.push_back({ temp,i });
        }
        sort(input.begin(), input.end(), compare);
        for (int i = 0; i < n; i++) {
            temp = f(0, input[i].second, 1, 0, n - 1) + 1;
            ans = max(ans, temp);
            //printf("%d\n", temp);
            update(1, input[i].second, 0, n - 1, temp);
        }

        printf("%d", tree[1]);
    }