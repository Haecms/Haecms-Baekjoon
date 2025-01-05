#include<stdio.h>
int main() {
	int n,m,a[10004], v;
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n * m; i++) a[i] = 0;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n * m; i++) {
			scanf("%d", &v);
			a[i] += v;
		}
	}
	for (int i = 0; i < n *m; i++) {
		printf("%d ", a[i]);
	}
}