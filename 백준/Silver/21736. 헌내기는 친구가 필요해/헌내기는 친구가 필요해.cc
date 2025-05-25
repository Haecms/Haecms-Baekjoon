#include<iostream>
#include<queue>
using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n, m, ret;
bool visited[604][604];
char a[604][604];
queue<pair<int, int>> q;
char c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'I') {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	while (q.size()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == 'X' || visited[ny][nx]) continue;
			if (a[ny][nx] == 'P') ret++;
			visited[ny][nx] = 1;
			q.push({ ny,nx });
		}
	}
	if (ret) cout << ret << "\n";
	else cout << "TT\n";
	return 0;
}