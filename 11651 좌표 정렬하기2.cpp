#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int compare(pair<int, int> a, pair<int, int> b) {
	if (a.second == b.second) {
		if (a.first < b.first)
			return true;
	}
	else if (a.second < b.second)
		return true;
	return false;
}

int main() {
	vector <pair<int, int>> x;
	int n;
	cin >> n;

	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		x.push_back({ a,b });
	}

	sort(x.begin(), x.end(), compare);

	for (int i = 0; i < n; i++) {
		cout << x[i].first << " " << x[i].second << '\n';
	}

	return 0;
}