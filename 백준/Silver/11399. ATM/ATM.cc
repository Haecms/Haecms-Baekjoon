#include<stdio.h>
int N, ret=0,time=0, a[1001], temp;
int main() 	{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) scanf("%d", &a[i]);
	for (int i = 0; i < N; i++) {
		for (int j = i + 1; j < N; j++) {
			if (a[i] > a[j]) {
				temp = a[i];
				a[i] = a[j];
				a[j] = temp;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		time = a[i] + time;
		ret += time;
	}
	printf("%d", ret);
	return 0;
}
