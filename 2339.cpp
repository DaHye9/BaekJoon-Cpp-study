#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
int num = 0;
int arr[21][21];
int cnt = 0;
int inputsize;

//con : 가로 0 세로 0
int divide(int a, int b, int c, int d, int con) {
	int check = 0;
	int checkednum = 0;
	int returnval = 0;
	vector<pair<int, int>> checked;

	if (a < 0 || b < 0 || c < 0 || d < 0 || a >= inputsize || b >= inputsize || c >= inputsize || d >= inputsize) return 1;
	//printf("%d %d %d %d\n", a, b, c, d);

	for (int i = a; i <= c; i++) {
		for (int k = b; k <= d; k++) {
			if (arr[i][k] == 2) {
				check++;
			}
			else if (arr[i][k] == 1) {
				checked.push_back(make_pair(i, k));
				checkednum++;
			}
		}
	}
	if (check == 1 && checkednum == 0) {
		if (a == 0 && b == 0 && c == inputsize - 1 && d == inputsize - 1) {
			if (con == 0) return 1;
			else return 0;
		}
	}
	if (check == 1) {
		if (checkednum == 0) return 1;
		else return 0;
	}
	else {
		for (int i = 0; i < checkednum; i++) {
			//printf("%d %d\n", checked[i].first, checked[i].second);
			int j = 1;
			if (con == 0) {
				for (int k = a; k <= c; k++) {
					if (arr[k][checked[i].second] == 2) j = 0;
				}
				if (j == 0) continue;
				returnval += divide(a, b, c, checked[i].second - 1, 1) * divide(a, checked[i].second + 1, c, d, 1);
			}
			else {
				for (int k = b; k <= d; k++) {
					if (arr[checked[i].first][k] == 2) j = 0;
				}
				if (j == 0) continue;
				returnval += divide(a, b, checked[i].first - 1, d, 0) * divide(checked[i].first + 1, b, c, d, 0);
			}
			//printf("%d\n", returnval);
		}
		return returnval;
	}
}

int main() {
	
	scanf("%d", &inputsize);
	for (int i = 0; i < inputsize; i++) {
		for (int k = 0; k < inputsize; k++) {
			scanf("%d", &arr[i][k]);
		}
	}
	
	int ret = divide(0, 0, inputsize - 1, inputsize - 1, 0) + divide(0, 0, inputsize - 1, inputsize - 1, 1);

	printf("%d", ret == 0 ? -1 : ret);
}