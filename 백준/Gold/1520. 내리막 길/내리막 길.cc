#include<iostream>
#include<memory.h>
using namespace std;
int n, m, a[504][504], dp[504][504];
int dy[4] = { 0,1,0, -1 };
int dx[4] = { 1,0,-1, 0 };

int go(int y, int x) {
	if (y == n-1 && x == m-1) return 1;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[y][x] <= a[ny][nx]) continue;
		ret += go(ny, nx);
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	memset(dp, -1, sizeof(dp));
	cout << go(0, 0) << "\n";
	return 0;
}