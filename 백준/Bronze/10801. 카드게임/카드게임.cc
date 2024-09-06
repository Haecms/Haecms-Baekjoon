#include<stdio.h>
int main() 	{
	int A[10],B[10], a=0, b=0;
	for (int i = 0; i < 20; i++) 
		i < 10 ? scanf("%d", &A[i]) : scanf("%d", &B[i-10]);
	for (int i = 0; i < 10; i++) {
		if (A[i] == B[i]) continue;
		A[i] > B[i] ? a += 1 : b += 1;
	}
	a == b ? printf("D") : a > b ? printf("A") : printf("B");
	return 0;
}
