#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
int t, n, a[2][100004], dp[2][100004];
int dy[4] = { 1,1,-1,-1 };
int dx[4] = { 1,2,1,2 };
int go(int y, int x) {
	if (y < 0 || x < 0 || y >= 2 || x >= n) return 0;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		ret = max(ret, go(ny, nx) + a[y][x]);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> n;
		memset(dp, -1, sizeof(dp));
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		cout << max(go(1, 0) ,go(0, 0)) << "\n";
	}
	return 0;
}