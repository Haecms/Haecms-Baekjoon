#include<stdio.h>
int n, m, k, f, t, a[1004], maxSum, ret;
int main() {
	scanf("%d %d", &n, &m);
	while (n--) {
		scanf("%d", &k);
		while (k--) {
			scanf("%d %d", &f, &t);
			for (int i = f; i < t; i++) a[i]++;
		}
	}
	for (int i = 0; i+m < 1001; i++) {
		int sum = 0;
		for (int j = i; j < i + m; j++) sum += a[j];
		if (sum > maxSum) {
			ret = i;
			maxSum = sum;
		}
	}
	printf("%d %d", ret, ret + m);
	return 0;
}