#include<stdio.h>
#include<vector>
#include<queue>
#include<tuple>
#include<memory.h>
using namespace std;
int n, m, visited[51][51], y, x, mx=0;
char a[51][51];
vector<pair<int, int>> v;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			scanf(" %c", &a[i][j]);
			if (a[i][j] == 'L') v.push_back({ i,j });
		}
	}
	int count=0;
	for (pair<int, int> p : v) {
		count++; 
		memset(visited, 0, sizeof(visited));
		visited[p.first][p.second] = 1;
		queue<pair<int, int>> q;
		q.push({ p.first, p.second });
		while (q.size()) {
			tie(y, x) = q.front(), q.pop();
			for (int i = 0; i < 4; i++) {
				int ny = dy[i] + y;
				int nx = dx[i] + x;
				if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx] || a[ny][nx] == 'W') continue;
				visited[ny][nx] = visited[y][x] + 1;
				q.push({ ny, nx });
				mx = max(mx, visited[ny][nx]);
;			}
		}
	}
	printf("%d", mx - 1);
}