#include<stdio.h>
int main() {
	char a;
	int ret=0,n=71;
	while (n--) {
		scanf("%c", &a);
		if (a == 'p' || a == 'P') ret += a == 'P' ? 1 : -1;
		else if (a == 'n' || a == 'N') ret += a == 'N' ? 3 : -3;
		else if (a == 'b' || a == 'B') ret += a == 'B' ? 3 : -3;
		else if (a == 'r' || a == 'R') ret += a == 'R' ? 5 : -5;
		else if (a == 'q' || a == 'Q') ret += a == 'Q' ? 9 : -9;
	}
	printf("%d", ret);
	
}
