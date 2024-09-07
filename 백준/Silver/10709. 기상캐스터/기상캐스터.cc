#include<stdio.h>
int main() {
	int n, m, cnt;
	char a[101];
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		cnt = -1;
		scanf("%s", &a, sizeof(a));
		for (int i = 0; i < m; i++) {
			if (a[i] == 'c') { printf("0 "); cnt = 0; }
			else printf("%d ", cnt == -1 ? -1 : ++cnt);
		}
		printf("\n");
	}
	return 0;
}
