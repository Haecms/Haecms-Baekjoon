#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[24][24], visited[100], ret;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
char c;

void dfs(int y, int x, int cnt) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[a[ny][nx]]) continue;
		visited[a[ny][nx]] = 1;
		dfs(ny, nx, cnt + 1);
		visited[a[ny][nx]] = 0;
	}
	ret = max(ret, cnt);
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			a[i][j] = c - 'A';
		}
	}
	visited[a[0][0]] = 1;
	dfs(0, 0, 1);
	cout << ret << "\n";
	return 0;
}