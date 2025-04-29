#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, a[20][20], dp[20][20][3];
int dy[3] = { 0,1,1 };
int dx[3] = { 1,1,0 };
int go(int y, int x, int direction) {
	if (y == n - 1 && x == n - 1) return 1;
    
	int& ret = dp[y][x][direction];
	if (ret != -1) { return ret; }
	ret = 0;
	for (int i = 0; i < 3; i++) {
		if (direction == 2 && i == 0) continue;
		if (direction == 0 && i == 2) continue;
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || a[ny][nx]) continue;
		if (i == 1 && a[y + dy[0]][x + dx[0]]) continue;
		if (i == 1 && a[y + dy[2]][x + dx[2]]) continue;
		ret += go(ny, nx, i);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> a[i][j];
	}
	memset(dp, -1, sizeof(dp));
	
	cout << go(0, 1, 0) << "\n";
}