#include<iostream>
#include<queue>
using namespace std;
int x, y, a[1004][1004], ret=-1, visited[1004][1004];
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
queue<pair<int, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> x >> y;
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			cin >> a[i][j];
			if (a[i][j] == 1) {
				q.push({ i,j });
				visited[i][j] = 1;
			}
		}
	}
	while (q.size()) {
		queue<pair<int, int>> q2;
		q2 = q;
		q = queue<pair<int, int>>();
		while (q2.size()) {
			int curY = q2.front().first;
			int curX = q2.front().second;
			q2.pop();
			for (int i = 0; i < 4; i++) {
				int ny = curY + dy[i];
				int nx = curX + dx[i];
				if (ny < 0 || nx < 0 || ny >= y || nx >= x || a[ny][nx] || visited[ny][nx]) continue;
				q.push({ ny,nx });
				visited[ny][nx] = 1;
			}
		}
		ret++;
	}
	for (int i = 0; i < y; i++) {
		for (int j = 0; j < x; j++) {
			if (visited[i][j] == 0 && a[i][j] == 0) ret = -1;
		}
	}
	cout << ret << "\n";
	return 0;
}