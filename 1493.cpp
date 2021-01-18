#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;
int check = 0;
int used = 0;
int arr[21];

bool compare(int a, int b) {
	return a < b;
}

int cal(int l, int w, int h, int ptr) {
	if (l == 0 || w == 0 || h == 0) return 1;
	int length = pow(2, ptr);
	while (arr[ptr] == 0 || length > l || length > w || length > h) {
		ptr--;
		length = pow(2, ptr);
	}
	if ((ptr == 0 && arr[ptr] == 0) || ptr<0) return 0;
	arr[ptr]--;
	used++;
	//printf("%d %d %d %d\n", l, w, h, ptr);
	//printf("%d %d\n", ptr, arr[ptr]);
	length = pow(2, ptr);
	return cal(length, w - length, length, ptr) && cal(l - length, w, length, ptr) && cal(l, w, h - length, ptr);
}

int main() {
	int l, w, h;
	int n;
	int ptr = 20;
	
	scanf("%d %d %d %d", &l, &w, &h, &n);
	for (int i = 0; i < n; i++) {
		int in1, in2;
		scanf("%d %d", &in1, &in2);
		arr[in1] = in2;
	}
	
	if (cal(l, w, h, 20)) printf("%d", used);
	else printf("-1");
	return 0;
}