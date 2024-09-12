#include<stdio.h>
char a[2];
int main() {
	int cnt = 0;
	char preString = ' ';
	while (scanf("%c", a)) {
		if (preString == ' ' && a[0] >= 65 && a[0] <= 133) cnt++;
		preString = a[0];
		if (a[0] == '\n') break;
	}
	printf("%d", cnt);

}