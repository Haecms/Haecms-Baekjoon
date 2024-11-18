#include<iostream>
using namespace std;
int n, a[11][11], visited[11][11], ret=987654321;
int dy[4] = { 1, 0, -1, 0 };
int dx[4] = { 0, -1, 0, 1 };
bool check(int y, int x) {
	for (int k = 0; k < 4; k++) {
		int ny = dy[k] + y;
		int nx = dx[k] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) return false;
	}
	return true;
}
void settingVisited(int y, int x, int value) {
	for (int k = 0; k < 4; k++) {
		int ny = dy[k] + y;
		int nx = dx[k] + x;
		visited[ny][nx] = value;
	}
	visited[y][x] = value;
}
void go(int y, int x, int count) {
	if (count == 3) {
		int curValue = 0;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) {
					curValue += a[i][j];
				}
			}
		}
		ret = min(ret, curValue);
	}
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visited[i][j]) continue;
				if (check(i, j)) {
					settingVisited(i, j, 1);
					go(i, j, count + 1);
					settingVisited(i, j, 0);
				}
			}
		}
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	go(0,0,0);
	cout << ret << "\n";
}