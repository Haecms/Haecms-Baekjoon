#include<iostream>
using namespace std;
int t, a[54][54], n,m,k, y, x;
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };

void go(int y, int x) {
	a[y][x] = 0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || !a[ny][nx]) continue;
		go(ny, nx);
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		cin >> m >> n >> k;
		for (int i = 0; i < k; i++) {
			cin >> x >> y;
			a[y][x] = 1;
		}
		int cnt=0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j]) {
					cnt++;
					go(i, j);
				}
			}
		}
		cout << cnt << "\n";
	}
	return 0;
}