#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int n, m, a[9][9], visited[9][9], ret;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<pair<int, int>> wall;
void go(int y, int x) {
	visited[y][x] = 2;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 1 || visited[ny][nx]) continue;
		go(ny, nx);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (!a[i][j]) wall.push_back({ i,j });
		}
	}
	for (int i = 0; i < wall.size() -2; i++) {
		for (int j = i + 1; j < wall.size() - 1; j++) {
			for (int k = j + 1; k < wall.size(); k++) {
				fill(&visited[0][0], &visited[0][0] + 9 * 9, 0);
				a[wall[i].first][wall[i].second]++;
				a[wall[j].first][wall[j].second]++;
				a[wall[k].first][wall[k].second]++;
				for (int y = 0; y < n; y++) {
					for (int x = 0; x < m; x++) {
						if (a[y][x] == 2 && !visited[y][x]) go(y, x);
					}
				}
				int cnt = 0;
				for (int y = 0; y < n; y++) {
					for (int x = 0; x < m; x++) {
						if (!a[y][x] && !visited[y][x]) cnt++;
					}
				}
				a[wall[i].first][wall[i].second]--;
				a[wall[j].first][wall[j].second]--;
				a[wall[k].first][wall[k].second]--;
                ret = max(ret, cnt);
			}
		}
	}
	cout << ret << "\n";
	return 0;
}