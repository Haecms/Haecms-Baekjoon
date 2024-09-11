#include<stdio.h>
int a, b[10001], c;
int main() {
	scanf("%d", &a);
	for (int i = 0; i < a; i++) {
		scanf("%d", &c);
		b[c] += 1;
	}
	
	for (int i = 0; i < 10001; i++) {
		while (b[i]) {
			printf("%d\n", i);
			b[i]--;
		}
	}
}