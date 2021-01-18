#include <algorithm>
#include <cstdio>
using namespace std;

//����Ŭ�̷�ų� �Ѹ��� �ڱ� �����ϰų�
int INF = 1010;
int cycle[1001]; //n�� ���Ұ� ��� ����Ŭ�� ���ϴ���
int visited[1001];
int arr[1001]; //�Է�
int n, k;
int cyclecnt = 0;
int cyclearr[1001];//n�� ����Ŭ�� �����ϴ� ������Ʈ ����
int cyclemin[1001];
int dparr[1001][1001];

void cyclecheck(int a) {
	int next = arr[a];
	visited[a] = 1;
	if (visited[next] == 1 && cycle[next] == 0) {
		cycle[a] = ++cyclecnt;
		cyclearr[cyclecnt]++;
		int temp = 0;
		for (int i = next; ; i = arr[i]) {
			cycle[i] = cyclecnt;
			//cyclearr[cyclecnt]++;
			temp++;
			if (i == a) {
				cyclearr[cyclecnt] = temp;
				cyclemin[cyclecnt] = temp;
				break;
			}
			if (cycle[i] != 0) {
				cyclearr[cyclecnt] = temp + cyclearr[cyclecnt];
				break;
			}
		}
	}
	else if (cycle[next] != 0) {
		cycle[a] = cycle[next];
		cyclearr[cycle[a]]++;
	}
	else {
		cyclecheck(next);
	}
}

int recheck(int a, int c) {//�� ����Ŭ ��ȣ ����
	if (c > n) return 0;
	if (cycle[a] == 0) {
		int end = recheck(arr[a], c + 1);
		if (end != 0) {
			cycle[a] = end;
			cyclearr[end]++;
			//printf("%d %d  %d\n", a, end, lcyclearr[end]);
		}
		return end;
	}
	else return cycle[a];
}

int dp(int a, int k) {
	if (a > cyclecnt) return 0;

	int result = dparr[a][k];
	if (result != -1) return result;
	for (int i = cyclemin[a]; k - i >= 0 && i <= cyclearr[a]; i++) {
		result = max(result, dp(a + 1, k - i) + i);
	}
	result = max(result, dp(a + 1, k));
	if (result == -1) result = -INF;
	dparr[a][k] = result;
	return result;
}
int main() {
	scanf("%d %d", &n, &k);
	for (int i = 1; i <= n; i++)scanf("%d", &arr[i]);

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) cyclecheck(i);
	}

	for (int i = 1; i <= n; i++) {
		if (cycle[i] == 0) recheck(i, 0);
	}

	for (int i = 0; i <= n; i++) {
		for (int j = 1; j <= k; j++) {
			dparr[i][j] = -1;
		}
	}
	
	for (int i = 1; i <= n; i++) {
		printf("%d %d %d\n", cycle[i], cyclemin[i], cyclearr[i]);
	}
	printf("%d", dp(1, k));
}