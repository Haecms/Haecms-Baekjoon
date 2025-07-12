#include<iostream>
#include<math.h>
using namespace std;
int n, r, c, w, o, p, a[5004][5004], ret, retX, retY;
pair<int, int> retp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> r >> c >> w;
	for (int i = 0; i < n; i++) {
		cin >> o >> p;
		a[o][p] = 1;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			a[i][j] += a[i - 1][j] + a[i][j - 1] - a[i-1][j-1];
		}
	}
	for (int x = 1; x <= r; x++) {
		for (int y = 1; y <= c; y++) {
			if (a[x][y] + a[x - 1][y - 1] - a[x][y - 1] - a[x - 1][y]) continue;
			int upY = min(y + w / 2, c);
			int upX = min(x + w / 2, r);
			int downY = max(y - w / 2 - 1, 0);
			int downX = max(x - w / 2 - 1, 0);
			if (ret < a[upX][upY] + a[downX][downY] - a[upX][downY] - a[downX][upY]) {
				ret = a[upX][upY] + a[downX][downY] - a[upX][downY] - a[downX][upY];
				retX = x;
				retY = y;
			}
		}
	}
	cout << ret << "\n" << retX << " " << retY << "\n";
	return 0;
}