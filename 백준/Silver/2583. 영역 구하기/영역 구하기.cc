#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, a,b,c,d, e[104][104], cnt;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
vector<int> ret;
void go(int y, int x) {
	e[y][x]++;
	cnt++;
	for (int i = 0; i < 4; i++) {
		int ny = dy[i] + y;
		int nx = dx[i] + x;
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || e[ny][nx])continue;
		go(ny, nx);
	}
}
int main() {
	cin >> n >> m >> k;
	while (k--) {
		cin >> a >> b >> c >> d;
		for (int i = b; i < d; i++) {
			for (int j = a; j < c; j++) {
				e[i][j]++;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!e[i][j]) {
				cnt = 0;
				go(i, j);
				ret.push_back(cnt);
			}
		}
	}
	sort(ret.begin(), ret.end());
	cout << ret.size() << "\n";
	for (int vv : ret) {
		cout << vv << " ";
	}
	return 0;
}