#include<stdio.h>
int main() {
	int a,b=0,c;
	for (int i = 1; i <= 81; i++) {
		scanf("%d", &a);
		if (b <= a) b = a, c = i;
	}
	printf("%d\n%d %d", b, c%9 ? c/9+1 : c/9, c%9 ? c%9 : 9);
}