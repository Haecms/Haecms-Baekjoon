#include<iostream>
#include<memory.h>
#include<algorithm>
using namespace std;
int n, z, ret, dp[504][504], a[504][504];

int go(int y, int x) {
	if (y == n-1) return a[y][x];
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = max(ret, go(y + 1, x) + a[y][x]);
	ret = max(ret, go(y + 1, x+1) + a[y][x]);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	fill(&dp[0][0], &dp[0][0] + 504 * 504, -1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	cout << go(0, 0) << "\n";
	return 0;
}