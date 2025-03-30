#include<stdio.h>
int n, m; char a[14];
int main() {
	scanf("%d%d", &n, &m);
	while (n--) {
		scanf("%s", a);
		for (int i = m - 1; i >= 0; i--) printf("%c", a[i]);
		printf("\n");
	}
	return 0;
}