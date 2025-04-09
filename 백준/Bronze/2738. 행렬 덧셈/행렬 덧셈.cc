#include<stdio.h>
int main() {
	int n, m, a[10004], v;
	scanf("%d %d", &n, &m);
	for (int i=0; i<n*m; i++) a[i] = 0;
	for (int i=0; i<n*m*2; i++) {
		scanf("%d", &v);
		a[i % (n*m)] += v;
	}
	for (int i=0; i<n*m; i++) {
		printf("%d ", a[i]);
	}
}