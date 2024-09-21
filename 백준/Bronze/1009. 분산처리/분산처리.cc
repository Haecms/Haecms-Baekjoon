#include<stdio.h>
int a, b, c, d;
int main() {
	scanf("%d", &c);
	while (c--) {
		scanf("%d%d", &a, &b);
		b = b%4 != 0 ? b%4 : 4;
		d = 1;
		while(b--) { d *= a; }
		printf("%d\n", d % 10 != 0 ? d % 10 : 10);
	}
	return 0;
}