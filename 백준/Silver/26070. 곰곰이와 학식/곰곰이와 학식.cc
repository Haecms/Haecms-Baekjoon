#include<stdio.h>
int main() {
	long long a, b, c, A, B, C, ret=0, ticket;
	scanf("%lld%lld%lld%lld%lld%lld", &a, &b, &c, &A, &B, &C);
	while (true) {
		if (a > A) { ret += A; a -= A; A = 0; }
		else { ret += a; A -= a; a = 0; }
		if (b > B) { ret += B; b -= B; B = 0; }
		else { ret += b; B -= b; b = 0; }
		if (c > C) { ret += C; c -= C; C = 0; }
		else { ret += c; C -= c; c = 0; }
		if (A > 3) {
			B += A / 3;
			A = A % 3;
			continue;
		}
		if (B > 3) {
			C += B / 3;
			B = B % 3;
			continue;
		}
		if (C > 3) {
			A += C / 3;
			C = C % 3;
			continue;
		}
		break;

	}
	printf("%lld", ret);
	return 0;
}
