#include<stdio.h>
int n, m, pkage, per, minPk=10000, minPer=10000, res;
int main() {
	scanf("%d%d", &n, &m);
	while (m--) {
		scanf("%d%d", &pkage, &per);
		minPk = pkage < minPk ? pkage : minPk;
		minPer = per < minPer ? per : minPer;
	}
	if (minPk / 6 < minPer) {
		res += (n / 6 * minPk);
		n %= 6;
		res += n * minPer < minPk ? n * minPer : minPk;
	}
	else res += n * minPer;
	printf("%d", res);
}
