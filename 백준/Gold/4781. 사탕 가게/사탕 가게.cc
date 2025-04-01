#include<memory.h>
#include<algorithm>
#include<string>
#include<stdio.h>
int cal, a[10004], n, m, money, d1, d2;
int main() {
	while (true) {
		scanf("%d %d.%d", &n, &m, &d1);
		if (n == 0 && m == 0.00) break;
		int mm = m * 100 + d1;
		memset(a, 0, sizeof(a));
		while (n--) {
			scanf("%d %d.%d", &cal, &money, &d2);
			int mmoney = money * 100 + d2;
			if (mmoney > mm) continue;
			for (int i = mmoney; i <= mm; i++) {
				a[i] = std::max(a[i], a[i - mmoney] + cal);
			}
		}
		printf("%d\n", a[mm]);
	}
}