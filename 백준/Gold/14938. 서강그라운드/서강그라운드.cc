#include<iostream>
#include<vector>
using namespace std;
int n, m, r, a, b, c, d, itemCnt[104], ret, visited[104];
vector<pair<int, int>> v[104];
int go(int cur, int nValue, int nDis) {
	visited[cur] = nDis+1;
	int value = 0;
	for (auto vv : v[cur]) {
		if (nDis + vv.second > m) continue;
		if (visited[vv.first]) {
			if (visited[vv.first] <= nDis + vv.second + 1) continue;
			value = value + go(vv.first, 0, nDis + vv.second);
		}
		else value = value + go(vv.first, itemCnt[vv.first], nDis + vv.second);
	}
	return nValue + value;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) { cin >> a, itemCnt[i] = a; }
	for (int i = 0; i < r; i++) {
		cin >> b >> c >> d;
		v[b].push_back({ c,d });
		v[c].push_back({ b,d });
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) visited[j] = 0;
		ret = max(ret, go(i, itemCnt[i], 0));
	}
	cout << ret << "\n";
	return 0;
}