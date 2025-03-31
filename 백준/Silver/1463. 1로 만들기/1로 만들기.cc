#include<iostream>
#include<algorithm>
using namespace std;
int n, dp[1000000];

int main() {
	cin >> n;
	fill(dp, dp + 1000000, 100000000);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[n] << "\n";
	return 0;
}