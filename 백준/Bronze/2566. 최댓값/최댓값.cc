#include<stdio.h>
int main() {
	int a,b=0,c,d;
	for (int i = 1; i <= 9; i++) {
		for (int j = 1; j <= 9; j++) {
			scanf("%d", &a);
			if (b <= a) {
				b = a;
				c = i;
				d = j;
			}
		}
	}
	printf("%d\n%d %d", b, c, d);
}