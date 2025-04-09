#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
const int dy[4] = { 0,0,-1,1 };
const int dx[4] = { 1,-1,0,0 };
// 1=> 빨간색, 2=> 파란색
int n, m, a[14][14], b,c,d, ret;
struct A { int y, x, direction, idx; };
vector<int> v[14][14];
A horse[10];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> b >> c >> d;
		horse[i].idx = v[b][c].size();
		horse[i].y = b;
		horse[i].x = c;
		horse[i].direction = --d;
		v[b][c].push_back(i);
		if (v[b][c].size() > 3) {
			cout << -1 << "\n";
			return 0;
		}
	}
	while (ret < 1002) {
		ret++;
		int cnt = 0;
		// 말의 이동
		for (int i = 0; i < m; i++) {
			// 현재 선택된 말
			int y = horse[i].y;
			int x = horse[i].x;
			int dir = horse[i].direction;
			int idx = horse[i].idx; // 현재 y,x 좌표의 idx번째에 위치해있음을 나타냄

			int ny = y + dy[dir];
			int nx = x + dx[dir];

			// 벽이거나 파란색 땅일 경우
			if (ny <= 0 || nx <= 0 || ny > n || nx > n || a[ny][nx] == 2) {
				dir ^= 1;
				ny = y + dy[dir];
				nx = x + dx[dir];
				
				if (ny <= 0 || nx <= 0 || ny > n || nx > n || a[ny][nx] == 2) { ny = y; nx = x; }
			}

			horse[i].y = ny;
			horse[i].x = nx;
			horse[i].direction = dir;

			// 이동이 없는 경우
			if (y == ny && x == nx) {
				cnt = max(cnt, (int)v[y][x].size());
				continue;
			}

			// 현재 판때기 좌표 위의 말 개수만큼 로직
			int nextCnt = v[ny][nx].size(); // 다음 판때기 좌표의 기존 말 개수
			for (int j = idx; j < v[y][x].size(); j++) {
				horse[v[y][x][j]].idx = v[ny][nx].size();
				horse[v[y][x][j]].y = ny;
				horse[v[y][x][j]].x = nx;
				v[ny][nx].push_back(v[y][x][j]);
			}

			cnt = max(cnt, (int)v[ny][nx].size());

			// 이동한 개수만큼 기존에 있던 곳에서 제거
			int vSize = v[y][x].size();
			for (int j = idx; j < vSize; j++) {
				v[y][x].pop_back();
			}

			// 빨간색 땅일 경우
			if (a[ny][nx] == 1) {
				reverse(v[ny][nx].begin() + nextCnt, v[ny][nx].end());

				for (int j = nextCnt; j < v[ny][nx].size(); j++) {
					horse[v[ny][nx][j]].idx = j;
				}
			}
		}
		if (cnt >= 4) break;
	}
	if (ret > 1000) cout << -1 << "\n";
	else cout << ret << "\n";
	return 0;
}