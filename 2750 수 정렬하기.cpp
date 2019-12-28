#include <iostream>
#include <algorithm>
using namespace std;

int main() {
	int n;
	int list[1000];
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> list[i];
	sort(list, list + n);
	for (int i = 0; i < n; i++)
		cout << list[i] << endl;

	return 0;
}