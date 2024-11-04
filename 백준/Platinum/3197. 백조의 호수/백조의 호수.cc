#include<iostream>
#include<tuple>
#include<queue>
using namespace std;
int R, C, swanY, swanX, visitedSwan[1504][1504], visitedWater[1504][1504], day = 0, y, x;
char a[1504][1504];
queue<pair<int, int>> waterQ;
queue<pair<int, int>> waterTempQ;
queue<pair<int, int>> swanQ;
queue<pair<int, int>> swanTempQ;
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
void Qclear(queue<pair<int,int>> &q) {
	queue<pair<int, int>> emptyQ;
	swap(q, emptyQ);
}
void waterMelting() {
	while (waterQ.size()) {
		tie(y, x) = waterQ.front();
		waterQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || visitedWater[ny][nx]) continue;
			if (a[ny][nx] == 'X') {
				visitedWater[ny][nx] = 1;
				a[ny][nx] = '.';
				waterTempQ.push({ ny,nx });
			}
		}
	}
}
bool moveSwan() {
	while (swanQ.size()) {
		tie(y, x) = swanQ.front();
		swanQ.pop();
		for (int i = 0; i < 4; i++) {
			int ny = dy[i] + y;
			int nx = dx[i] + x;
			if (ny < 0 || nx < 0 || ny >= R || nx >= C || visitedSwan[ny][nx]) continue;
			visitedSwan[ny][nx] = 1;
			if (a[ny][nx] == '.') swanQ.push({ ny, nx });
			else if (a[ny][nx] == 'X') swanTempQ.push({ ny, nx });
			else if (a[ny][nx] == 'L') return true;
		}
	}
	return false;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> R >> C;
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
			if (a[i][j] == 'L') { swanY = i, swanX = j; }
			if (a[i][j] == '.' || a[i][j] == 'L') { visitedWater[i][j] = 1, waterQ.push({ i,j }); }
		}
	}
	swanQ.push({ swanY,swanX });
	visitedSwan[swanY][swanX] = 1;
	while (true) {
		if (moveSwan()) break;
		waterMelting();
		waterQ = waterTempQ;
		swanQ = swanTempQ;
		Qclear(waterTempQ);
		Qclear(swanTempQ);
		day++;
	}
	cout << day << "\n";
	return 0;
}