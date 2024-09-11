#include<bits/stdc++.h>
using namespace std;
int n, m, visited[51][51], mx=0;
char a[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	queue<pair<int, int>> q;
	q.push({ y, x});
	while (q.size()) {
		tie(y, x) = q.front(), q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[y][x] + 1;
			q.push({ ny, nx });
			mx = max(mx, visited[ny][nx]);
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (a[i][j] == 'L') bfs(i, j);
	}
	printf("%d", mx - 1);
}