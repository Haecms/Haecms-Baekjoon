#include<iostream>
#include<vector>
using namespace std;
int n, m, a[101][101], visited[101][101], cnt, cnt2;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<pair<int, int>> v;
void go(int y, int x) {
	visited[y][x] = 1;
	if (a[y][x] == 1) { v.push_back({ y,x }); return; }
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (nx < 0 || ny < 0 || nx >= m || ny >= n || visited[ny][nx]) continue;
		go(ny, nx);
	}
}
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	while (true) {
		fill(&visited[0][0], &visited[0][0] + 101 * 101, 0);
		v.clear();
		go(0, 0);
		cnt2 = v.size();
		for (pair<int, int> i : v) a[i.first][i.second] = 0;
		bool check = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i][j] == 1) { check = 1; break; }
			}
		}
		cnt++;
		if (!check) break;
	}
	cout << cnt << '\n' << cnt2 << '\n';
}
