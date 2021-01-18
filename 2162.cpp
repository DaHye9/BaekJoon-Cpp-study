
#pragma once

long long n, groupcnt;
long long parent[3001], input[3001][4];

long long find(long long x) {
	if (parent[x] < 0)return x;
	parent[x] = find(parent[x]);
	return parent[x];
}

long long ccw(long long x11, long long y11, long long x12, long long y12) {
	long long ret = x11 * y12 - y11 * x12;
	return ret;
}


void merge(long long a, long long b) {
	a = find(a); b = find(b);
	if (a == b) {
		return;
	}
	parent[a] += parent[b];
	parent[b] = a;
}


int main() {
	scanf("%lld", &n);
	memset(parent, -1, sizeof(parent));
	for (long long i = 0; i < n; i++) {
		scanf("%lld %lld %lld %lld", &input[i][0], &input[i][1], &input[i][2], &input[i][3]);
		long long j;
		long long state = 0;
		for (j = 0; j < i; j++) {
			long long a = ccw(input[i][0] - input[j][0], input[i][1] - input[j][1], input[i][2] - input[j][0], input[i][3] - input[j][1]) * ccw(input[i][0] - input[j][2], input[i][1] - input[j][3], input[i][2] - input[j][2], input[i][3] - input[j][3]);
			long long b = ccw(input[j][0] - input[i][0], input[j][1] - input[i][1], input[j][2] - input[i][0], input[j][3] - input[i][1]) * ccw(input[j][0] - input[i][2], input[j][1] - input[i][3], input[j][2] - input[i][2], input[j][3] - input[i][3]);
			if (a <= 0 && b <= 0) {
				if((input[i][0]>input[j][0]&&input[i][0]>input[j][2]&&input[i][2]>input[j][0]&&input[i][2]>input[j][2])||(input[i][0] < input[j][0] && input[i][0] < input[j][2] && input[i][2] < input[j][0] && input[i][2] < input[j][2])) continue;
				if ((input[i][1] > input[j][1] && input[i][1] > input[j][3] && input[i][3] > input[j][1] && input[i][3] > input[j][3]) || (input[i][1] < input[j][1] && input[i][1] < input[j][3] && input[i][3] < input[j][1] && input[i][3] < input[j][3])) continue;
				if (a == 0 && b == 0) {
					if ((max(input[j][0], input[j][2]) < min(input[i][0], input[i][2])) ||
						(max(input[i][0], input[i][2]) < min(input[j][0], input[j][2])) ||
						(max(input[j][1], input[j][3]) < min(input[i][1], input[i][3])) ||
						(max(input[i][1], input[i][3]) < min(input[j][1], input[j][3]))) continue;
				}
				merge(j, i);
			}
		}
	}
	long long ans = 0;
	for (long long i = 0; i < n; i++) {
		// prlong longf("%d\n", parent[i]);
		if (parent[i] < 0)groupcnt++;
		ans = min(ans, parent[i]);
	}
	printf("%lld\n%lld", groupcnt, -ans);
}
