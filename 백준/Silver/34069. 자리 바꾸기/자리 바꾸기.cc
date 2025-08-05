#include<iostream>
using namespace std;
int n, m, a[504][504], visited[504][504], visitedCnt;
int dy[2] = { 0,1 };
int dx[2] = { 1,0 };

void go(int y, int x) {
	if (visitedCnt == n * m) {
		cout << "Yes\n";
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cout << a[i][j] << " ";
			}
			cout << "\n";
		}
		exit(0);
	}
	int dir = m % 2 == 1;
	for (int i = y; i < n; i++) {
		for (int j = x; j < m; j++) {
			int ny = dy[dir] + i;
			int nx = dx[dir] + j;
			if (ny < 0 || nx < 0 || ny >= n || nx >= m || visited[i][j] || visited[ny][nx]) continue;
			int temp = a[i][j];
			a[i][j] = a[ny][nx];
			a[ny][nx] = temp;
			visited[i][j] = 1;
			visited[ny][nx] = 1;
			visitedCnt += 2;
			go(i, j + 1);
		}
		x = 0;
	}
}

int main() {
	;
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	if ((n * m) % 2) cout << "No\n";
	else {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> a[i][j];
			}
		}
		go(0, 0);
	}
	return 0;

}