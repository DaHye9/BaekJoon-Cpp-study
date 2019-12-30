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
	//stable sort �ϱ� ���ؼ� index �� �߰����ذ���
	sort(x.begin(), x.end()); //������ �ڿ������� ���ϴ°Ŵϱ� �׳� sort ���൵ ��

	for (int i = 0; i < n; i++) {
		cout << x[i].va << " " << x[i].vc << '\n';
	}

	return 0;
}