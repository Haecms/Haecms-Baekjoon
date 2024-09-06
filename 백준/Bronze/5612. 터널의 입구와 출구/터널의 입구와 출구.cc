#include<stdio.h>
int main() {
	int n, m, N,M, r;
	scanf("%d %d", &n, &m);
	int s = r = m;
	while (n--) {
		scanf("%d %d", &N, &M);
		s += N - M;
		r = s > r ? s : r;
		if (s < 0) break;
	}
	s < 0 ? printf("%d", 0) : printf("%d", r);
}