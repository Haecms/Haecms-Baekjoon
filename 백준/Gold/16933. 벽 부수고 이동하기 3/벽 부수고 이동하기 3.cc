#include<iostream>
#include<queue>

using namespace std;

int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };

int n, m, k, a[1004][1004], visited[1004][1004][2], macnt[1004][1004][2], ret=-1;
string s;
struct A { int y, x, cnt; bool morning; };
queue<A> q;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);

	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (int j = 0; j < m; j++) a[i][j] = s[j] - '0';
	}
	q.push({ 0,0,0,1 });
	visited[0][0][1] = 1;	

	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int cnt = q.front().cnt;
		bool morning = q.front().morning;
		bool changeTime = bool(morning ^ 1);
		q.pop();

		if (y == n - 1 && x == m - 1) {
			ret = visited[y][x][morning];
			break;
		}

		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];
			if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			
			if (morning) {
				// 벽 부수기
				if (a[ny][nx] && cnt + 1 <= k && (!visited[ny][nx][changeTime] || macnt[ny][nx][changeTime] > cnt + 1)) {
					visited[ny][nx][changeTime] = visited[y][x][morning] + 1;
					macnt[ny][nx][changeTime] = cnt + 1;
					q.push({ ny,nx,cnt + 1,changeTime });
				}
			}
			else {
				// 대기
				if (!visited[y][x][changeTime] || macnt[y][x][changeTime] > cnt) {
					visited[y][x][changeTime] = visited[y][x][morning] + 1;
					macnt[y][x][changeTime] = cnt;
					q.push({ y,x,cnt, changeTime });
				}
			}

			// 상하좌우 이동 
			if (!a[ny][nx] && (!visited[ny][nx][changeTime] || macnt[ny][nx][changeTime] > cnt)) {
				q.push({ ny,nx,cnt,changeTime });
				visited[ny][nx][changeTime] = visited[y][x][morning] + 1;
				macnt[ny][nx][changeTime] = cnt;
			}
		}
	}
	cout << ret << "\n";
	return 0;
}