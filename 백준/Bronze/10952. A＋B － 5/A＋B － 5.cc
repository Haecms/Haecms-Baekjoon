#include<stdio.h>
int main() {
	int a,b;
	while (true) {
		scanf("%d %d", &a, &b);
		if (!a && a == b) break;
		printf("%d\n", a + b);
	}
}