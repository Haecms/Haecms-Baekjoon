#include<stdio.h>
int main() {
	int N,W,H,L;
	scanf("%d", &N); scanf("%d", &W); scanf("%d", &H); scanf("%d", &L);
	N = (W / L) * (H / L) > N ? N : (W / L) * (H / L);
	printf("%d", N);
}
