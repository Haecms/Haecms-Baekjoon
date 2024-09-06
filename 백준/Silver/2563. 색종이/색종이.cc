#include<stdio.h>
int N, A[101][101],x,y,cnt=0;
int main() 	{
	scanf("%d", &N);
	for (int i = 1; i <= N; i++) {
		scanf("%d%d", &x, &y);
		for (int j = x; j < x + 10; j++) {
			for (int k = y; k < y + 10; k++) {
				if (A[j][k]) continue;
				A[j][k] = i;
				cnt++;
			}
		}
	}
	printf("%d", cnt);
	return 0;
}
