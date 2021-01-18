#include <cstdio>
#include <vector>
#include <queue>
#include <string.h> 
#include <cmath>
#include <algorithm>
#include <tuple>

using namespace std;

#define pii pair <int,int>
#define ll long long

long long INF = 1e18;
using namespace std;

int n, indegree[30], visit[30], num;
char str[103][13], ans[30];
vector<char> rel[30];

int main() {
	scanf("%d", &n);
	int stat = 0;


	for (int i = 0; i < n; i++) {
		scanf("%s", &str[i]);
		for (int k = 0; str[i][k] != '\0'; k++) {
			int temp = str[i][k] - 'a';
			if (visit[temp] == 0) {
				num++;
				visit[temp] = 1;
			}
		}
	}

	for (int i = 0; i < n - 1; i++) {
		int k;
		for (k = 0; (str[i][k] != '\0') && (str[i][k] == str[i + 1][k]); k++);
		if (str[i][k] == '\0') {
			continue;
		}
		else {
			if (str[i + 1][k] == '\0') {
				printf("!");
				return 0;
			}
			//printf("%c %c\n", str[i][k], str[i+1][k]);
			rel[str[i][k] - 'a'].push_back(str[i + 1][k]);
			indegree[str[i + 1][k] - 'a']++;
			continue;
		}
	}
	queue <char> q;
	for (int i = 0; i < 24; i++)
		if (visit[i] == 1 && indegree[i] == 0) {
			q.push((char)(i + 'a'));
			//printf("%c\n", i + 'a');
		}

	int t;
	for (t = 0; t < num; t++) {
		if (q.empty()) {
			printf("!");
			return 0;
		}
		char curr = q.front();
		q.pop();
		ans[t] = curr;

		//printf("%c\n", curr);

		if (q.size() != 0) {
			stat = 1;
		}
		for (int i = 0; i < rel[curr - 'a'].size(); i++) {
			if (--indegree[rel[curr - 'a'][i] - 'a'] == 0) {
				//printf("%c\n", rel[curr - 'a'][i]);
				q.push(rel[curr - 'a'][i]);
			}
		}
	}

	if (stat == 1) printf("?");
	else {
		for (int i = 0; i < num; i++) {
			printf("%c", ans[i]);
		}
	}
	return 0;
}