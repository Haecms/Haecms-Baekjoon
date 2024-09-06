#include<stdio.h>
int main() {
	int a, b, c;
	while (true) {
		scanf("%d %d %d", &a, &b, &c);
		if (a==0 && b==0 && c==0) break;
		int ret=0;
		bool y = false;
		if (c % 4 == 0 && c % 100 != 0 || c % 400 == 0) y = true;
		for (int i = 1; i < b; i++) {
			if (i == 2) ret += y ? 29 : 28;
			else if (i == 4 || i == 6 || i == 9 || i == 11) ret += 30;
			else ret += 31;
		}
		printf("%d\n", ret + a);
	}
	return 0;
}
