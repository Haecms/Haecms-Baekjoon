#include<iostream>
using namespace std;
int n, m, k, arr[104][104], r, c, cnt, visited[104][104], realCnt = 0;
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,1,0, -1 };

void check(int y, int x ) {
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny <= 0 || nx <= 0 || ny > n + 1 || nx > m + 1 || visited[ny][nx] || !arr[ny][nx]) continue;
		visited[ny][nx] = visited[y][x] + 1;
		cnt++;
		check(ny, nx);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	while (k--) {
		cin >> r >> c;
		arr[r][c] = 1;
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (arr[i][j] && !visited[i][j]) {
				visited[i][j] = 1;
				cnt = 1;
				check(i, j);
				realCnt = max(realCnt, cnt);
			}
		}
	}
	cout << realCnt << "\n";
	return 0;
}