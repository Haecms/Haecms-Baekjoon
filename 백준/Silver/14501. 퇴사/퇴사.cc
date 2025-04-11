#include<iostream>
#include<vector>
using namespace std;
int n, t,p,dp[1005];
vector<pair<int, int>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> t >> p;
		v.push_back({ t,p });
	}
	for (int i = 0; i < n; i++) {
		int useTime = v[i].first;
		int value = v[i].second;
		if (i + useTime <= n) {
			dp[i + useTime] = max(dp[i + useTime], dp[i] + value);
		}
		dp[i + 1] = max(dp[i], dp[i + 1]);
	}
	cout << dp[n] << "\n";
	return 0;
}