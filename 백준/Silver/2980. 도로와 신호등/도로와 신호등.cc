#include<stdio.h>
int main() {
	int n, m, d, r, g, time = 0, prevd = 0;
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d%d%d", &d, &r, &g);
		time += d - prevd;
		prevd = d;
		time += time%(r+g) >= r ? 0 : r - time%(r+g);
	}
	printf("%d", time + (m-prevd));
	return 0;
}
