#include<stdio.h>
int n, m, a;
int main() {
	scanf("%d%d%d", &n,&m,&a);
	int d = n - m;
	(a-n) % d ? printf("%d", (a-n)/d+2) : printf("%d", (a-n)/d+1);
}