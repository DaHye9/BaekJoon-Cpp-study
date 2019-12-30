#include <iostream>
#include <algorithm>
#include <vector>
#define va first.first
#define vb first.second
#define vc second

using namespace std;

typedef pair<pair<int, int>, string > pii;

int main() {
	int n;
	cin >> n;
	vector <pii> x;

	for (int i = 0; i < n; i++) {
		int a;
		string b;
		cin >> a >> b;
		x.push_back({ { a,i }, b });
	}
	//stable sort 하기 위해서 index 값 추가해준거임
	sort(x.begin(), x.end()); //같으면 뒤에꺼까지 비교하는거니까 그냥 sort 해줘도 됨

	for (int i = 0; i < n; i++) {
		cout << x[i].va << " " << x[i].vc << '\n';
	}

	return 0;
}