#include<bits/stdc++.h>
using namespace std;
int n, m, visited[51][51], mx = 0,z[2501], t[2501], P,T;
char a[51][51];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void bfs(int y, int x) {
	memset(visited, 0, sizeof(visited));
	visited[y][x] = 1;
	z[0] = y; t[0] = x; P = 0; T = 0;
	int count = 1;
	while (count--) {
		int cy = z[P];
		int cx = t[P++];
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + cy;
			int nx = dx[i] + cx;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'W') continue;
			visited[ny][nx] = visited[cy][cx] + 1;
			count++;
			z[++T] = ny;
			t[T] = nx;
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