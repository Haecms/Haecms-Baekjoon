#include<iostream>
using namespace std;
int n, m, k, a[14], dp[14][1 << 13][21], ret;
void go(int bagCnt, int nValue, int use, int visit) {
	if (dp[bagCnt][visit][nValue]) return;
	dp[bagCnt][visit][nValue] = 1;
	if (bagCnt == m || visit == (1 << n) - 1) {
		ret = max(ret, (int)__builtin_popcount(use));
		return;
	}
	for (int i = 0; i < n; i++) {
		if (visit & (1 << i)) continue;
		if (a[i] > k) go(bagCnt, nValue, use, visit | (1 << i));
		else {
			if (nValue + a[i] > k) {
				if (bagCnt + 1 == m) go(bagCnt + 1, 0, use, visit);
				else go(bagCnt + 1, a[i], use | (1 << i), visit | (1 << i));
			}
			else go(bagCnt, nValue + a[i], use | (1 << i), visit | (1 << i));
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	go(0, 0, 0, 0);
	cout << ret << "\n";
	return 0;
}