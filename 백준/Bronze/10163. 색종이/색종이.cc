#include<stdio.h>
int N, A[1001][1001],x,y,w,h, C[101];
int main() 	{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d %d %d %d", &x, &y, &w, &h);
		for (int j = x; j < x + w; j++) {
			for (int k = y; k < y + h; k++) {
				A[j][k] = i;
			}
		}
	}
	for (int i = 0; i < N; i++) C[i] = 0;
	for (int i = 0; i < 1001; i++) {
		for (int j = 0; j < 1001; j++) C[A[i][j]]++;
	}
	for (int i = 1; i <= N; i++) printf("%d\n", C[i]);
	return 0;
}
