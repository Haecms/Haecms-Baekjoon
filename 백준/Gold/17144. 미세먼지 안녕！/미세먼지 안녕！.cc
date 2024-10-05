#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
int r, c, t, realMap[51][51], copyMap[51][51], ret = 0;
vector<pair<int, int>> v;
int dy[4] = { -1,0,1,0 };
int dx[4] = { 0,1,0,-1 };
void setDust(int y, int x) {
	int cnt=0;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= r || nx >= c || realMap[ny][nx] == -1) continue;
		copyMap[ny][nx] += realMap[y][x] / 5;
		cnt++;
	}
	copyMap[y][x] += realMap[y][x] - (realMap[y][x] / 5 * cnt);
}
int main() {
	cin >> r >> c >> t;
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> realMap[i][j];
			if (realMap[i][j] == -1) v.push_back({ i,j });
		}
	}
	while (t--) {
		memset(copyMap, 0, sizeof(copyMap));
		// 1. 먼지의 확산
		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				if (realMap[i][j] == -1) copyMap[i][j] = -1;
				else if (realMap[i][j] == 0) continue;
				else setDust(i, j);
			}
		}
		// 2. 공기청정기 작동
		int vy = v[0].first;
		int vx = v[0].second + 1;
		int memory_dust_prev = 0;
		int memory_dust_next = 0;
		while (realMap[vy][vx] != -1) {
			memory_dust_next = copyMap[vy][vx];
			copyMap[vy][vx] = memory_dust_prev;
			memory_dust_prev = memory_dust_next;

			if (vy == v[0].first && vx + 1 < c)  vx++; 
			else if (vy - 1 >= 0 && vx == c-1) vy--;
			else if (vy == 0 && vx -1 >= 0)  vx--; 
			else if (vy +1 < r && vx ==0) vy++; 
		}
		vy = v[1].first;
		vx = v[1].second + 1;
		memory_dust_prev = 0;
		memory_dust_next = 0;
		while (realMap[vy][vx] != -1) {
			memory_dust_next = copyMap[vy][vx];
			copyMap[vy][vx] = memory_dust_prev;
			memory_dust_prev = memory_dust_next;

			if (vy == v[1].first && vx + 1 < c)  vx++; 
			else if (vy + 1 < r && vx == c-1)  vy++; 
			else if (vy == r - 1 && vx - 1 >= 0)  vx--; 
			else if (vy - 1 >= v[1].first && vx == 0)  vy--; 
		}

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				realMap[i][j] = copyMap[i][j];
			}
		}
	}
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (realMap[i][j] > 0)ret += realMap[i][j];
		}
	}
	cout << ret << "\n";
}