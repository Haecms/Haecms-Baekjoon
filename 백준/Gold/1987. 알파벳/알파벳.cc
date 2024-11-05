#include<iostream>
using namespace std;
int R, C, visited[30], cnt=0;
char a[24][24];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
void dfs(int y, int x, int count){
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= R || nx >= C || visited[a[ny][nx] - 'A']) continue;
		visited[a[ny][nx] - 'A'] = 1;
		dfs(ny, nx, count + 1);
		visited[a[ny][nx] - 'A'] = 0;
	}
	cnt = max(count, cnt);
}
int main() {
	cin >> R >> C;
	for (int i = 0; i < R; i++){
		for (int j = 0; j < C; j++) {
			cin >> a[i][j];
		}
	}
	visited[a[0][0] - 'A'] = 1;
	dfs(0,0,1);
	cout << cnt << "\n";
}