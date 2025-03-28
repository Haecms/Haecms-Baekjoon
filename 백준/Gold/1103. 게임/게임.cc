#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[54][54], visited[54][54], dp[54][54];
char c;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

bool in(int y, int x) { return (y >= 0 && x >= 0 && y < n && x < m && a[y][x] != ('H' - '0')); }

int go(int y, int x) {
	if (!in(y, x)) return 0;
	if (visited[y][x]) {
		cout << -1 << "\n";
		exit(0);
	}
	int& ret = dp[y][x];
	if (ret) return ret;
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i] * a[y][x];
		int nx = x + dx[i] * a[y][x];
		ret = max(ret, go(ny, nx) + 1);
	}
	visited[y][x] = 0;
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> c, a[i][j] = c - '0';
	}
	cout << go(0, 0) << "\n";
	return 0;
}