#include<iostream>
using namespace std;
int n, m, t, k, a, b, realVisited[104][104], sumVisited[104][104];
char c;
int main() {
	cin >> n >> m >> t >> k >> a >> b;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> c;
			if (c == '*')	realVisited[i][j] = 1;
			else realVisited[i][j] = 0;
		}
	}
	while (t--) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sumVisited[i][j] = realVisited[i][j] + sumVisited[i - 1][j] + sumVisited[i][j - 1] - sumVisited[i - 1][j - 1];
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				int Y1 = max(1, i - k);
				int X1 = max(1, j - k);
				int Y2 = min(n, i + k);
				int X2 = min(m, j + k);
				int current = sumVisited[Y2][X2] + sumVisited[Y1 - 1][X1 - 1] - sumVisited[Y2][X1 - 1] - sumVisited[Y1 - 1][X2] - realVisited[i][j];
				if (realVisited[i][j]) {
					if (current < a) realVisited[i][j] = 0;
					else if (current > b) realVisited[i][j] = 0;
				}
				else if(current >a && current <=b)  realVisited[i][j] = 1;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (realVisited[i][j] == 1) cout << '*';
			else cout << '.';
		}
		cout << "\n";
	}
}