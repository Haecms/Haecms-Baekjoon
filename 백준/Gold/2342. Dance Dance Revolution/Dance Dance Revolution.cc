#include<iostream>
#include<vector>
using namespace std;
int n, dp[5][5][100004];
vector<int> v;
int check(int prev, int cur) {
	if (!prev) return 2;
	if (prev == cur) return 1;
	if (abs(prev - cur) == 2) return 4;
	return 3;
}
int go(int y, int x, int idx) {
	if (idx == v.size()) return 0;
	int& ret = dp[y][x][idx];
	if (ret) return ret;
	ret = 2000000000;
	ret = min(ret, go(v[idx], x, idx + 1) + check(y, v[idx]));
	ret = min(ret, go(y, v[idx], idx + 1) + check(x, v[idx]));
	return ret;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	while (1) {
		cin >> n;
		if (!n) break;
		v.push_back(n);
	}
	cout << go(0, 0, 0) << "\n";
	return 0;
}