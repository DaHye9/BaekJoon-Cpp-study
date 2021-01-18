#include <cstdio>
#include <vector>
#include <map>
#include <queue>
using namespace std;

int t, m;
priority_queue <int, vector <int>, greater <int>> minq;
priority_queue <int, vector <int>, less <int>> maxq;
int mid = -1;
int ans[10000];

int main() {
	scanf("%d", &t);
	for (int i = 0; i < t; i++) {
		scanf("%d", &m);
		int temp;
		int cnt = 1;
		printf("%d\n", (m+1)/2);
		for (int j = 0; j < m; j++) {
			scanf("%d", &temp);
			if (j == 0) {
				mid = temp;
				ans[cnt++] = mid;
				continue;
			}
			if (mid == -1) {
				if (maxq.top() <= temp && minq.top() >= temp) { //같은 경우 고려 안해줘서 틀림 ㅡㅡ;
					mid = temp;
				}
				else if (maxq.top() > temp) {
					mid = maxq.top();
					maxq.pop();
					maxq.push(temp);
				}
				else if (minq.top() < temp) {
					mid = minq.top();
					minq.pop();
					minq.push(temp);
				}
			}
			else {
				if (temp < mid) {
					maxq.push(temp);
					minq.push(mid);
					mid = -1;
				}
				else {
					minq.push(temp);
					maxq.push(mid);
					mid = -1;
				}
			}
			if (mid != -1) {//홀수개 들어오면
				ans[cnt++] = mid;
			}
			//if ((j + 2) % 20 == 0)printf("\n");
		}
		while (!minq.empty()) minq.pop();
		while (!maxq.empty()) maxq.pop();
		mid = -1;
		for (int k = 1; k <= (m + 1) / 2; k++) {
			printf("%d ", ans[k]);
			if (k % 10 == 0)printf("\n");
		}
		printf("\n");
	}
}