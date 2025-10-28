#include<iostream>
using namespace std;
int n, m, x, y, k, a[24][24], b;
int dy[5] = { 0, 0,0,-1,1 };
int dx[5] = { 0, 1,-1,0,0 };
int dice[4][4]{
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0},
	{0,0,0,0}
};
void setPlace(int bottomY, int bottomX) {
	int temp = dice[bottomY][bottomX];
	if (a[y][x]) {
		dice[1][3] = a[y][x];
		dice[3][1] = a[y][x];
		a[y][x] = 0;
	}
	else {
		a[y][x] = temp;
		dice[bottomX][bottomY] = temp;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> y >> x >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while (k--) {
		cin >> b;
		int ny = y + dy[b];
		int nx = x + dx[b];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		y = ny;
		x = nx;
		if (b == 1) {
			int temp = dice[1][3];
			for (int i = 3; i > 0; i--) {
				dice[1][i] = dice[1][i - 1];
			}
			dice[1][0] = temp;
			setPlace(1, 3);
		}
		else if (b == 2) {
			int temp = dice[1][0];
			for (int i = 0; i < 3; i++) {
				dice[1][i] = dice[1][i + 1];
			}
			dice[1][3] = temp;
			setPlace(1, 3);
		}
		else if (b == 3) {
			int temp = dice[0][1];
			for (int i = 0; i < 3; i++) {
				dice[i][1] = dice[i + 1][1];
			}
			dice[3][1] = temp;
			setPlace(3, 1);
		}
		else if (b == 4) {
			int temp = dice[3][1];
			for (int i = 3; i > 0; i--) {
				dice[i][1] = dice[i - 1][1];
			}
			dice[0][1] = temp;
			setPlace(3, 1);
		}
		cout << dice[1][1] << "\n";
	}
	return 0;
}