#include <iostream>

using namespace std;
//������ ũ�� ���� ���� ī���� ��Ʈ�� ������. ��Ȯ�� �˰����� �˻� ��.
const int maxx = 10001; //���� ó���� max�� �߾��µ� std::max()�� �־ reference�� ambigious�ϴٰ� ���ͼ� �ٲ��ذ���
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