#include<iostream>
#include<math.h>
using namespace std;
int n, r, c, w, a[5004][5004],o,p, aa[5004][5004], ret;
pair<int, int> retp;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> r >> c >> w;
	for (int i = 0; i < n; i++) {
		cin >> o >> p;
		a[o][p] = 1;
		aa[o][p] = 1;
	}
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			aa[i][j] += aa[i - 1][j] + aa[i][j - 1] - aa[i-1][j-1];
		}
	}
	for (int x = 1; x <= r; x++) {
		for (int y = 1; y <= c; y++) {
			if (a[x][y]) continue;
			int upY = min(y + w / 2, c);
			int upX = min(x + w / 2, r);
			int downY = max(y - w / 2 - 1, 0);
			int downX = max(x - w / 2 - 1, 0);
			if (ret < aa[upX][upY] + aa[downX][downY] - aa[upX][downY] - aa[downX][upY]) {
				ret = aa[upX][upY] + aa[downX][downY] - aa[upX][downY] - aa[downX][upY];
				retp.first = x;
				retp.second = y;
			}
		}
	}
	cout << ret << "\n" << retp.first << " " << retp.second << "\n";
	return 0;
}