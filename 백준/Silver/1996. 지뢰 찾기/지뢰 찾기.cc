#include<iostream>
using namespace std;
char c[1004][1004], c_c[1004][1004];
int n;
int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			c_c[i][j] = '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (c[i][j] != '.') {
				c_c[i][j] = '*';
				for (int k = 0; k < 8; k++) {
					int ny = dy[k] + i;
					int nx = dx[k] + j;
					if (ny < 0 || nx < 0 || ny >= n || nx >= n || c[ny][nx] != '.') continue;
					int many = (c_c[ny][nx] - '0') + (c[i][j] - '0');
					c_c[ny][nx] = many >= 10 ? 'M' : many + '0';
				}
			}
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << c_c[i][j];
		}
		cout << "\n";
	}
}