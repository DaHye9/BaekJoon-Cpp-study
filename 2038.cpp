#include <cstdio>
#include <algorithm>
#include <math.h>
#include <cstring>
#define pii pair<int,int>
#define MAX 30000000
using namespace std;
int arr[MAX];
int n, pos = 1, subpos = 2;

int main() {
	scanf("%d", &n);
	arr[1] = 1;
	arr[2] = 2;
	int temp = 1;
	while (pos < n) {
		int k = arr[subpos % MAX];
		temp++;
		for (int i = 1; i <= k; i++) {
			pos++;
			arr[pos % MAX] = temp;
			printf("%d %d\n", pos % MAX, temp);
		}
		subpos++;
	}
	printf("%d", arr[pos % MAX]);
}
//이렇게 하려다가 