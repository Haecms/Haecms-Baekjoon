#include<iostream>
#include<queue>
using namespace std;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int n, m, a[104][104], visited[104][104];
char c;
struct A {
	int y, x, cnt;
	bool operator<(const A& b) const { return cnt > b.cnt; }
};
priority_queue<A> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	pq.push({ 0,0,1 });
	visited[0][0] = 1;
	while (pq.size()) {
		int y = pq.top().y;
		int x = pq.top().x;
		int cnt = pq.top().cnt;
		pq.pop();
		if (y == m - 1 && x == n - 1) {
			cout << cnt - 1 << "\n";
			break;
		}
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
			if (visited[ny][nx] && visited[ny][nx] <= cnt + a[ny][nx]) continue;
			visited[ny][nx] = cnt + a[ny][nx];
			pq.push({ ny,nx, cnt + a[ny][nx] });
		}
	}
	return 0;
}