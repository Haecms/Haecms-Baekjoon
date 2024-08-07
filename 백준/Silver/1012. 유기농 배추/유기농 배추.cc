#include <bits/stdc++.h>
using namespace std;
const int max_n = 54;
int T,N,M,K, y, x;
int a[max_n][max_n];
int visited[max_n][max_n];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
void dfs(int ny, int nx) {
	visited[ny][nx] = 1;
	for (int i = 0; i < 4; i++) {
		int py = ny + dy[i];
		int px = nx + dx[i];
		if (py < 0 || py >= M || px < 0 || px >= N || a[py][px] ==0) continue;
		if (visited[py][px]) continue;
		dfs(py, px);
	}
}
int main() {
	cin >> T;
	for (int i = 0; i < T; i++) {
		int ret = 0;
		cin >> N >> M >> K;
		for (int j = 0; j < K; j++) {
			cin >> x >> y;
			a[y][x] = 1;
		}
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				if (a[j][k] && !visited[j][k]) {
					dfs(j, k);
					ret++;
				}
			}
		}
		cout << ret << "\n";
		for (int j = 0; j < M; j++) {
			for (int k = 0; k < N; k++) {
				a[j][k] = 0;
				visited[j][k] = 0;
			}
		}
	}
}