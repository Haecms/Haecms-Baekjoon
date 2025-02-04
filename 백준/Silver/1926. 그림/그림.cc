#include<iostream>
using namespace std;
int n, m, a[501][501], visited[501][501], fncSize, picSize, cnt;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

void go(int y, int x) {
	visited[y][x] = 1;
	fncSize++;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (!a[ny][nx] || visited[ny][nx]) continue;
		go(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] && !visited[i][j]) {
				cnt++;
				fncSize = 0;
				go(i, j);
				picSize = fncSize > picSize ? fncSize : picSize;
			}
		}
	}
	cout << cnt << "\n" << picSize << "\n";
}