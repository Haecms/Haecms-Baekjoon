#define ABS(x) ((x) >= 0 ? (x) : -(x))
#include<stdio.h>
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 1; i <=n*2-1; i++) {
		for (int j = 0; j < ABS(n - i); j++) printf(" ");
		for (int j = 1; j < (n - ABS(n - i)) * 2; j++) printf("*");
		printf("\n");
	}
}