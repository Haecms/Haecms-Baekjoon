#include<stdio.h>
int n, m, a[104], c, d;
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= n; i++) a[i] = i;
	for (int i = 0; i < m; i++) {
		scanf("%d %d", &c, &d);
		while (c < d) {
			int t = a[c];
			a[c++] = a[d];
			a[d--] = t;
		}
	}
	for (int i = 1; i <= n; i++) printf("%d ", a[i]);
}