#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int compare(string a, string b) {
	if (a.length() < b.length())
		return 1; 
	else if (a.length()==b.length()) {
		if (a < b)
			return 1;
	}
	return 0;
}
	
int main() {
	int n;
	cin >> n;
	vector <string> x;

	for (int i = 0; i < n; i++) {
		string c;
		cin >> c;
		x.push_back(c);
	}

	sort(x.begin(), x.end(), compare);

	int num = unique(x.begin(), x.end())- x.begin(); //�ߺ� ���� �ٲ� �� ������ iterator�� �ּҰ� ��������

	for (int i = 0; i < num; i++) {
		cout << x[i] << '\n';
	}

	return 0;
}