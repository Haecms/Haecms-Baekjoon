#include<iostream>
#include<algorithm>
using namespace std;
int n, dp[1000004];

void go(int a) {
	if (a <= 0) return;
	cout << a << " ";
	if (!(a % 3) && dp[a] == dp[a / 3] + 1) go(a / 3);
	else if (!(a % 2) && dp[a] == dp[a / 2] + 1) go(a / 2);
	else if (dp[a] == dp[a - 1] + 1) go(a - 1);
}

int main() {
	cin >> n;
	fill(dp, dp + 1000004, 100000000);
	dp[1] = 0;
	for (int i = 1; i <= n; i++) {
		if (!(i % 3)) dp[i] = min(dp[i / 3] + 1, dp[i]);
		if (!(i % 2)) dp[i] = min(dp[i / 2] + 1, dp[i]);
		dp[i] = min(dp[i], dp[i - 1] + 1);
	}
	cout << dp[n] << "\n";
	go(n);
	return 0;
}