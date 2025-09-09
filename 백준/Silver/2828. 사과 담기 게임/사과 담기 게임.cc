#include<stdio.h>
int n, j, a, li=1, ri, ret;
int main() {
	scanf("%d%d%d", &n, &ri, &j);
	while (j--) {
		scanf("%d", &a);
		while (li > a) { ret++; li--; ri--; }
		while (ri < a) { ret++; li++; ri++; }
	}
	printf("%d", ret);
	return 0;
}