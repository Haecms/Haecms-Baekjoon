#include<iostream>
#include<queue>

using namespace std;

int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
int n, m, k, a[1004][1004], visited[1004][1004], macnt[1004][1004], ret = -1;
string s;
struct A { int y, x, cnt; };
queue<A> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) { a[i][j] = s[j] - '0'; }
	}
	q.push({ 0,0,0 });
	visited[0][0] = 1;

	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		q.pop();

		if (macnt[y][x] < cnt) continue;

		if (y == n - 1 && x == m - 1) {
			ret = visited[y][x];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;

			if (a[ny][nx] && cnt+1 <= k && (cnt+1 < macnt[ny][nx] || !visited[ny][nx])) {
				q.push({ ny,nx,cnt + 1 });
				visited[ny][nx] = visited[y][x] + 1; 
				macnt[ny][nx] = cnt + 1;
			}
			
			if (!a[ny][nx] && (macnt[ny][nx] > cnt || !visited[ny][nx])) {
				q.push({ ny,nx,cnt });
				visited[ny][nx] = visited[y][x] + 1;
				macnt[ny][nx] = cnt;
			}
		}
	}

	cout << ret << "\n";

	return 0;
}

