#include<iostream>
using namespace std;
int n, dp[1500004], t,p;
pair<int, int> a[1500004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	for (int i = n-1; i >= 0; i--) {
		if (i + a[i].first > n) {
			dp[i] = dp[i + 1];
			continue;
		}
		dp[i] = max(dp[i+1], dp[i + a[i].first] + a[i].second);
	}
	cout << dp[0] << "\n";
	return 0;
}