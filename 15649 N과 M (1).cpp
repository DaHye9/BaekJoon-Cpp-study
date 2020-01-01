#include <iostream>

using namespace std;

int visited[9];
int arr[8];
int n, m;

void print(int count) {
	if (count == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
		return;
	}

	for (int i = 1; i <= n; i++) {
		if (visited[i] == 0) {
			arr[count] = i;
			visited[i] = 1;
			print(count + 1); //첨에 ++count 했다가 이거 계속 count++되니깐 몇 개 안나와서.. 일케 바꿈 ㅋㅋ
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> m;

	print(0);

	return 0;
}