#include <algorithm>
#include <cstdio>
#include <vector>
using namespace std;

int l, c;
int isvowel[26];
char input[15];
char output[16];

void backtracking(int pos, int prev, int notvowel, int vowel) {
	if (pos == l && vowel >= 1 && notvowel>= 2) {
		for (int i = 0; i < l; i++) {
			printf("%c", output[i]);
		}
		printf("\n");
		return;
	}

	for (int i = prev + 1; i < c; i++) {
		output[pos] = input[i];
		backtracking(pos + 1, i, notvowel + !isvowel[input[i] - 'a'], vowel + isvowel[input[i] - 'a']);
	}
}

int main() {
	scanf("%d %d", &l, &c);
	for (int i = 0; i < c; i++) {
		scanf(" %c", &input[i]);
	}
	sort(input, input + c);
	isvowel[0] = isvowel[4] = isvowel[8] = isvowel[14] = isvowel[20] = 1;

	backtracking(0, -1, 0, 0);
}