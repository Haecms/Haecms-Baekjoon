#include <bits/stdc++.h>
using namespace std;
const int max_n = 101;
int N, ny, nx, ret = 0;
int a[max_n][max_n], visited[max_n][max_n];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, -1, 0, 1 };

void dfs(int y, int x, int k) {
	visited[y][x] = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= N) continue;
		if (a[ny][nx] <= k || visited[ny][nx]) continue;
		dfs(ny, nx, k);
	}
}

int main() {
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> a[i][j];
		}
	}
	for (int k = 0; k < 101; k++) {
		fill(&visited[0][0], &visited[0][0] + max_n * max_n, 0);
		int count = 0;
		for (int i = 0; i < N; i++) {
			for (int j = 0; j < N; j++) {
				if (a[i][j] > k && !visited[i][j]) {
					dfs(i, j, k);
					count++;
				}
			}
		}
		ret = max(ret, count);
	}
	cout << ret << '\n';
}