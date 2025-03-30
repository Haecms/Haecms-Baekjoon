#include<stdio.h>
int n, m, a[14],d; char c;
int main() {
	scanf("%d%d", &n, &m);
	while (n--) {
		d = m; while (d--) scanf(" %c", &c), a[m - d] = c - '0';
		d = m+1; while(--d) printf("%d", a[d]); printf("\n");
	}
	return 0;
}