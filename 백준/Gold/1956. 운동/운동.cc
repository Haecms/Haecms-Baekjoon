#include<iostream>
#include<math.h>
#include<memory.h>
using namespace std;
int n, m, dp[404][404],a,b,c,z[404][404], ret = 1e9;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	fill(&dp[0][0], &dp[0][0] + 404 * 404, 1e9);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) z[i][i] = 1e9;
	for (int i = 1; i <= n; i++) dp[i][i] = 0;
	while (m--) {
		cin >> a >> b >> c;
		dp[a][b] = min(dp[a][b], c);
		z[a][b] = dp[a][b];
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dp[i][j] = min(dp[i][j], dp[k][j] + dp[i][k]);
			}
		}
	}
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			if (dp[k][i] == 1e9 || dp[i][k] == 1e9 || !dp[k][i] || !dp[i][k]) continue;
			z[k][k] = min(z[k][k], dp[k][i] + dp[i][k]);
			ret = min(ret, z[k][k]);
		}
	}
	cout << (ret == 1e9 ? -1 : ret) << "\n";
	return 0;
}