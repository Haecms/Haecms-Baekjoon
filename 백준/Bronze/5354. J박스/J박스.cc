#include<stdio.h>
int main() {
	int n,m;
	scanf("%d", &n);
	while (n--) {
		scanf("%d", &m);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < m; j++) {
				i == 0 || i == m - 1 || j == 0 || j == m - 1 ? printf("#") : printf("J");
			}
			printf("\n");
		}
		printf("\n");
	}
}
