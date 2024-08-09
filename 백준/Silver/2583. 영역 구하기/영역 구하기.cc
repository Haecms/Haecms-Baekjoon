#include <bits/stdc++.h>
using namespace std;
const int max_n = 101;
int a[max_n][max_n], visited[max_n][max_n];
int N, M, K, l_x, l_y, r_x, r_y, ny, nx;
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
vector<int> ret;

int dfs(int y, int x) {
	visited[y][x] = 1;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		ny = y + dy[i];
		nx = x + dx[i];
		if (ny < 0 || ny >= N || nx < 0 || nx >= M) continue;
		if (visited[ny][nx] || a[ny][nx]) continue;
		ret += dfs(ny, nx);
	}
	return ret;
}
 
int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL); cout.tie(NULL);
	cin >> N >> M >> K;

	for (int i = 0; i < K; i++) {
		cin >> l_x >> l_y >> r_x >> r_y;
		for (int j = l_y; j < r_y; j++) {
			for (int k = l_x; k < r_x; k++) {
				a[j][k] = 1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (!visited[i][j] && !a[i][j]) {
				ret.push_back(dfs(i, j));
				
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int a : ret) cout << a << " ";
}