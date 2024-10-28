#include<iostream>
#include<queue>
using namespace std;
int n, m, startX, startY, arriveX, arriveY, visited[301][301];
char curMap[301][301];
int dy[4] = { 1,0,-1,0 };
int dx[4] = { 0,-1,0,1 };
queue<pair<int, int>> q;
queue<pair<int, int>> q2;
int main() {
	cin >> n >> m;
	cin >> startY >> startX >> arriveY >> arriveX;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> curMap[i][j];
		}
	}

	q.push({ startY - 1, startX - 1 });
	visited[startY - 1][startX - 1] = 1;
	int turnCnt = 0;
	bool flag = false;
	while (q.size()) {
		int qSize = q.size();
		turnCnt++;
		while (qSize--) {
			int qy = q.front().first;
			int qx = q.front().second;
			q2.push({ qy,qx });
			q.pop();
			while (q2.size()) {
				int qy2 = q2.front().first;
				int qx2 = q2.front().second;
				q2.pop();
				for (int i = 0; i < 4; i++) {
					int cnt = 0;
					while (true) {
						cnt++;
						int ny = qy2 + (dy[i] * cnt);
						int nx = qx2 + (dx[i] * cnt);
						if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[ny][nx]) break;
						if (curMap[ny][nx] == '#') {
							visited[ny][nx] = turnCnt;
							flag = true;
							break;
						}
						if (curMap[ny][nx] == '1') {
							visited[ny][nx] = turnCnt;
							curMap[ny][nx] = '0';
							q.push({ ny, nx });
							break;
						}
						visited[ny][nx] = turnCnt;
						q2.push({ ny, nx });
					}
					if (flag) break;
				}
				if (flag) break;
			}
			if (flag) break;
		}
		if (flag) break;
	}
	cout << visited[arriveY-1][arriveX-1] << "\n";
}