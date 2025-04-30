#include<stdio.h>
#include<math.h>
int main() {
	int n,i=1,j;
	scanf("%d", &n);
	for (; i<n*2; i++) {
		for (j=0; j<n-abs(n-i); j++) printf("*");
		for (j=0; j<abs(n-i)*2; j++) printf(" ");
		for (j=0; j<n-abs(n-i); j++) printf("*");
		printf("\n");
	}
}