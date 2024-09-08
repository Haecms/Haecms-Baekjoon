#include<stdio.h>
int c[200002], g[200002];
int main() {
	long long a, b, ret=0, d, e, f;
	scanf("%lld", &a);
	for (long long i = 1; i <= a; i++) {
		scanf("%lld", &c[i]);
		ret += c[i]; g[i] = 0;
	}
	scanf("%lld", &b); printf("%lld\n", ret);
	while (b--) {
		scanf("%lld", &d);
		d == 1 ? scanf("%lld%lld", &e, &f) : scanf("%lld", &e);
		if (d == 1) {
			if(!g[e]) ret += f-c[e];
			c[e] = f;
		}
		else {
			if (g[e]) ret += c[e];
			else ret -= c[e];
			g[e] = g[e] ? 0 : 1;
			
		}
		printf("%lld\n", ret);
	}
	return 0;
}
