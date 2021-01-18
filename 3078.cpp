#include <algorithm>
#include <queue>
#include <string>
#include <iostream>
using namespace std;

long long ans= 0;
queue <int>q[21];
int n, k;

int main() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		string temp;
		cin >> temp;
		int length = temp.length();

		while (!q[length].empty() && i - q[length].front() > k) {
			q[length].pop();
		}
		ans += q[length].size();
		q[length].push(i);
	}

	cout << ans;
}