#include<iostream>
#include<vector>
using namespace std;
int n, m, a[9][9], v[9][9], cntR=0;
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { 1, 0, -1, 0 };
vector<pair<int, int>> wall;
vector<pair<int, int>> virus;

void insfection(int y, int x) {
	v[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
		if (a[ny][nx] > 0 || v[ny][nx] > 0) continue;
		insfection(ny, nx);
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (!a[i][j]) wall.push_back({ i, j });
			if (a[i][j] == 2) virus.push_back({ i,j });
		}
	}
	for (int i = 0; i < wall.size(); i++) {
		for (int j = 0; j < i; j++) {
			for (int k = 0; k < j; k++) {
				a[wall[i].first][wall[i].second] = 1;
				a[wall[j].first][wall[j].second] = 1;
				a[wall[k].first][wall[k].second] = 1;
				fill(&v[0][0], &v[0][0] + 9 * 9, 0);
				for (int h = 0; h < virus.size(); h++) {
					insfection(virus[h].first, virus[h].second);
				}
				int cnt=0;
				for (int h = 0; h < n; h++) {
					for (int p = 0; p < m; p++) {
						if (v[h][p] == 0 && a[h][p] == 0) cnt++;
					}
				}
				cntR = max(cntR, cnt);
				a[wall[i].first][wall[i].second] = 0;
				a[wall[j].first][wall[j].second] = 0;
				a[wall[k].first][wall[k].second] = 0;
			}
		}
	}
	cout << cntR << '\n';
}