#include <cstdio>
#include <algorithm>
#include <stack>
using namespace std;

int n;
int result = 0;
int input[1002];
stack <int> st1;
stack <int> st2;

int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		scanf("%d", &input[temp]);
	}
	st1.push(0);
	st2.push(1001);

	int top1, top2;
	
	for (int i = 0; i < 1001; i++) {
		if (input[i] != 0 && input[st1.top()] < input[i]) st1.push(i);
		if (input[1000 - i] != 0 && input[st2.top()] < input[1000 - i]) st2.push(1000 - i);
	}

	top1 = st1.top();
	top2 = st2.top();
	//printf("%d %d\n", top1, top2);

	while (st1.size() >= 2) {
		int right = st1.top();
		st1.pop();
		int left = st1.top();
		result += (right - left) * input[left];
		//printf("1 %d %d %d\n", right, left, result);
	}
	while (st2.size() >= 2) {
		int left = st2.top();
		st2.pop();
		int right = st2.top();
		result += (right - left) * input[right];
		//printf("2 %d %d %d\n", right, left, result);
	}

	result += (top2 - top1 + 1) * input[top1];
	/*
	이렇게 말고 한번 스택에 넣을때마다 그때의 max height를 더해주는 방법도 있음
	처음에 굳이 푸시 할필요 없이 엠티면 처음꺼 푸시하는 방법도 있고
	*/

	printf("%d", result);

}