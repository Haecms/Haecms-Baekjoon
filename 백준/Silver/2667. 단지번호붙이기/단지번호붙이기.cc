#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a[26][26];
char c;
vector<int> v;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
int go(int y, int x) {
	a[y][x] = 0;
	int ret = 1;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= n || !a[ny][nx]) continue;
		ret += go(ny, nx);
	}
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j]) {
				v.push_back(go(i, j));
			}
		}
	}
	sort(v.begin(), v.end());
	cout << v.size() << "\n";
	for (int ret : v) cout << ret << "\n";
	return 0;
}