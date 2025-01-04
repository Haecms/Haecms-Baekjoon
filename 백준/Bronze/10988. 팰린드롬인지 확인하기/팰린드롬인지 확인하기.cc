#include<stdio.h>
#include<string.h>
int main() {
	char c[104];
	scanf("%s", c);
	int flag = 1;
	for (int i = 0; i < strlen(c); i++) {
		if (c[i] != c[strlen(c) - 1 - i]) {
			flag = 0;
			break;
		}
	}
	printf("%d", flag);
}