#include<stdio.h>
#include<algorithm>
int n, m, a, b, c[104], ret, cs=1;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d %d", &a, &b);
		for (int j = cs; j < a + cs; j++) c[j] = b;
		cs += a;
	}
	cs = 1;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &a, &b);
		for (int j = cs; j < a+cs; j++) ret = std::max(ret, b-c[j]);
		cs += a;
	}
	printf("%d", ret);
	return 0;
}