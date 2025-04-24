#include<iostream>
#include<math.h>
using namespace std;
int a[225], n, dp[50004];
int go(int idx, int nValue) {
	if (nValue == n) return 0;
	int& ret = dp[nValue];
	if (ret != 100000) return ret;
	ret = 90000;
	for (int i = idx; i < 225; i++) {
		if (nValue + a[i] <= n) ret = min(ret, go(i, nValue + a[i]) + 1);
		else break;
	}
	return ret;
}
int main() {
	for (int i = 1; i < 225; i++) a[i] = i * i;
	cin >> n;
	fill(dp, dp + 50004, 100000);
	cout << go(0, 0) << "\n";
	return 0;
}