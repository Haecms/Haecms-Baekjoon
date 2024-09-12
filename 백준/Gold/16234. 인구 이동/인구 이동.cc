#include<iostream>
using namespace std;
int n, l, r, a[51][51], visited[51][51], area, area_cnt, area_sum, divide_person[2501];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void bfs(int y, int x, int area) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
		if (abs(a[y][x] - a[ny][nx]) < l || abs(a[y][x] - a[ny][nx]) > r) continue;
		visited[ny][nx] = area;
		area_cnt++;
		area_sum += a[ny][nx];
		bfs(ny, nx, area);
	}
}
int main() {
	cin >> n >> l >> r;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int cnt = 0;
	while (true) {
		area = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (!visited[i][j]) {
					area_cnt = 1;
					area_sum = a[i][j];
					visited[i][j] = area;
					bfs(i, j, area);
					divide_person[area] = area_sum / area_cnt;
					area++;
				}
			}
		}
		if (area - 1 == n * n) break;
		cnt++;
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++) {
				a[j][k] = divide_person[visited[j][k]];
				visited[j][k] = 0;
			}
		}
		for (int i = 0; i < area; i++) {
			divide_person[i] = 0;
		}
	}
	cout << cnt;
}