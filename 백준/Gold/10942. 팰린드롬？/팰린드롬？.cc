#include<iostream>
#include<memory.h>
using namespace std;
int n, m, a[2004],f,t, dp[2004][2004];

int go(int y, int x) {
	if (y > x) return 1;
	int& ret = dp[y][x];
	if (ret != -1) return ret;
	ret = 0;
	if (a[y] == a[x]) ret = go(y + 1, x - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	cin >> m;
	memset(dp, -1, sizeof(dp));
	while (m--) {
		cin >> f >> t;
		cout << go(f,t) << "\n";
	}
	return 0;
}