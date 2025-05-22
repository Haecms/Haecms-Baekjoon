#include<stdio.h>
int n, a, b[4] = { 25,10,5,1 };
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &a);
		for (int i = 0; i < 4; i++) {
			printf("%d ", a / b[i]);
			a %= b[i];
		}
		printf("\n");
	}
	return 0;
}