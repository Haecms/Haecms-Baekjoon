#include<stdio.h>
int T, m, n, M[101][101];
int main() 	{
	scanf("%d", &T);
	while (T--) {
		scanf("%d %d", &m, &n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &M[i][j]);
			}
		}
		int distance = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (M[j][i] && j < m-1) {
					int cnt=0;
					for (int k = j+1; k < m; k++) {
						if (!M[k][i]) cnt++;
					}
					distance += cnt;
				}
			}
		}
		printf("%d\n", distance);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				M[i][j] = 0;
			}
		}
	}
	return 0;
}
