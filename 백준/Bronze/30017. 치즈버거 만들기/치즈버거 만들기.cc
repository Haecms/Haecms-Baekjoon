#include<stdio.h>
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	if (n > m) printf("%d", m + m + 1);
	else printf("%d", n + n - 1);
}