#include <iostream>
#include <algorithm>

using namespace std;

int Answer, n, k;
int a[200010], b[200010];

int main(int argc, char** argv)
{
	int T, test_case;

	cin >> T;
	for (test_case = 0; test_case < T; test_case++)
	{
		cin >> n >> k;

		for (int i = 0; i < n; i++) {
			cin >> a[i];
		}

		for (int i = 0; i < n; i++) {
			cin >> b[i];
		}

		sort(a, a + n);
		sort(b, b + n);

		for (int i = 0; i < k; i++) {
			Answer = max(Answer, a[i] + b[k - i - 1]);
		}
		cout << "Case #" << test_case + 1 << endl;
		cout << Answer << endl;

		Answer = 0;
	}

	return 0;
}