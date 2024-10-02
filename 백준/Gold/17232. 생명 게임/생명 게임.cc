#include<iostream>
using namespace std;
int n, m, t, k, a, b, realVisited[104][104], copyVisited[104][104];
char c[104][104];

void check(int y, int x) {
	int cnt=0;
	for (int i = y - k; i <= y + k; i++) {
		if (i < 0 || i>=n) continue;
		for (int j = x - k; j <= x + k; j++) {
			if (j < 0 || j>=m) continue;
			if (i == y && j == x) continue;
			if (realVisited[i][j]) cnt++;
		}
		if (cnt < a || cnt > b) copyVisited[y][x] = 0;
	}
	if (cnt < a || cnt > b) copyVisited[y][x] = 0;
	else if (!realVisited[y][x] && cnt > a && cnt <= b) copyVisited[y][x] = 1;
	else if (realVisited[y][x] && cnt >= a && cnt <= b) copyVisited[y][x] = 1;
}

int main() {
	cin >> n >> m >> t >> k >> a >> b;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c[i][j];
			if (c[i][j] == '*') {
				realVisited[i][j] = 1;
				copyVisited[i][j] = 1;
			}
		}
	}
	while (t--) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				check(i,j);
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				realVisited[i][j] = copyVisited[i][j];
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (realVisited[i][j]) cout << "*";
			else cout << ".";
		}
		cout << "\n";
	}
}
