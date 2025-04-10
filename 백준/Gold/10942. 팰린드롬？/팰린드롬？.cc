#include<iostream>
using namespace std;
int n, m, a[2004],f,t, dp[2004][2004];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	for (int i = 1; i <= n; i++) dp[i][i] = 1;
	for (int i = 1; i <= n; i++) {
		if (a[i] == a[i+1]) dp[i][i + 1] = 1;
	}
	for (int i = 2; i <= n; i++) {
		for (int j = 1; j <= n - i; j++) {
			if (a[j] == a[i + j] && dp[j + 1][j + i - 1]) dp[j][j + i] = 1;
		}
	}
	while (m--) {
		cin >> f >> t;
		cout << dp[f][t] << "\n";
	}
	return 0;
}