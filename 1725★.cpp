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
	for (int i = 1; i < n + 1; i++) { //넓이랑 관련된 문제 -> 1부터 n까지
		scanf("%d", &arr[i]);
	}

	st.push(0);
	for (int i = 1; i <= n + 1; i++) {
		while (!st.empty() && arr[st.top()] > arr[i]) {
			int h = arr[st.top()];
			st.pop();
			int w = i - st.top() - 1; //팝할수록 높이가 낮아지는 형태, 맨 오른쪽은 오른쪽부터 넓이라는 점 종합
			result = max(result, h * w);
		}
		st.push(i);
	}

	printf("%d", result);
}