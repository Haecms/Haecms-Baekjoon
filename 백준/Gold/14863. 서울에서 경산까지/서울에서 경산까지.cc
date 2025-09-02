#include<iostream>
using namespace std;
int n, k, dp[100004],a,b,c,d,ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	dp[0] = 1;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		for (int j = k; j >= 0; j--) {
			if (dp[j]) {
				if (j + a <= k) dp[j + a] = max(dp[j + a], dp[j] + b);
				if (j + c <= k) dp[j + c] = max(dp[j + c], dp[j] + d);
				dp[j] = 0;
			}
		}
	}
	for (int i = 0; i <= k; i++) {
		ret = max(ret, dp[i]);
	}
	cout << ret-1 << "\n";
	return 0;
}