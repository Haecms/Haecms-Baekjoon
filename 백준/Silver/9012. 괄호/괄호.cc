#include <stdio.h>
#pragma warning(disable:4996)
int main() {
	int n;
	scanf("%d", &n);
	while (n--) {
		char s[51];
		scanf("%s", s); int l = 0, r = 0;
		for (char a : s) {
			if (a == '\0') break;
			a == '(' ? l++ : l--;
			if (l < 0) { r++; break; }
		}
		l != 0 || r != 0 ? printf("NO\n") : printf("YES\n");
	}
}
