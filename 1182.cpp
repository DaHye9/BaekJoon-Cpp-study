#include <iostream>
using namespace std;

int cnt;
int arr[20];
int n, s;

void a(int i, int temp) {
	if (i >= n) return;
	temp+=arr[i];
	if (temp == s) cnt++;

	a(i + 1, temp);
	a(i + 1, temp - arr[i]);
}

int main() {

	scanf("%d %d", &n, &s);
	cnt = 0;

	for (int i = 0; i < n; i++) {
		scanf("%d", &arr[i]);
	}

	a(0, 0);

	printf("%d", cnt);
	
	return 0;
}