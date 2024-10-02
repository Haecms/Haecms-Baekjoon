#include<iostream>
#include<queue>
using namespace std;
int n, m, visited[1004][1004], homeCnt = 0, destroiedHomeCnt = 0;
char a[1004][1004];
int dy[4] = { 0,-1,1,0 };
int dx[4] = { 1,0,0,-1 };
queue<pair<int, int>> destroied;

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
			if (a[i][j] == '#') {
				homeCnt++;
				visited[i][j] = 2;
			}
			else if (a[i][j] == '*') {
				homeCnt++;
				visited[i][j] = 1;
			}
			else if (a[i][j] == '@') destroied.push({ i,j });
		}
	}
	while (destroied.size()) {
		int y = destroied.front().first;
		int x = destroied.front().second;
		destroied.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == '|') continue;
			if (a[y][x] == '@') {
				visited[ny + dy[i]][nx + dx[i]]--;
				if (!visited[ny + dy[i]][nx + dx[i]]) {
					homeCnt--;
					destroiedHomeCnt++;
					destroied.push({ ny + dy[i],nx + dx[i] });
				}
			}
			visited[ny][nx]--;
			if (!visited[ny][nx]) {
				homeCnt--;
				destroiedHomeCnt++;
				destroied.push({ ny,nx });
			}
		}
	}
	cout << destroiedHomeCnt << " " << homeCnt<< "\n";
}