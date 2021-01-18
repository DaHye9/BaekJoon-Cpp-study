#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

stack <int> st;
int arr[1000010];
int n;
int result = 0;

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n + 1; i++) { //���̶� ���õ� ���� -> 1���� n����
		scanf("%d", &arr[i]);
	}

	st.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int h = arr[st.top()];
			st.pop();
			int w = i - st.top() - 1; //���Ҽ��� ���̰� �������� ����, �� �������� �����ʺ��� ���̶�� �� ����
			result = max(result, h * w);
		}
		st.push(i);
	}

	printf("%d", result);
}