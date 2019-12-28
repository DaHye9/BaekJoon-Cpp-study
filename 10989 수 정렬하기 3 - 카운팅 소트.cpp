#include <iostream>

using namespace std;
//범위가 크지 않을 때는 카운팅 소트도 괜찮다. 정확한 알고리즘은 검색 ㄱ.
const int maxx = 10001; //원래 처음에 max로 했었는데 std::max()가 있어서 reference가 ambigious하다고 나와서 바꿔준거임
int list[maxx];

int main() {
	int n;


	fill_n(list, maxx, 0);

	cin >> n;

	for (int i = 0; i < n; i++) {
		int temp;
		scanf("%d", &temp);
		list[temp]++;
	}
	for (int i = 1; i < maxx; i++) {
		while (list[i]-- != 0) {
			printf("%d\n", i);
		}
	}

	return 0;
}