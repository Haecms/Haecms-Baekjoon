#include<iostream>
#include<vector>
using namespace std;
int n, m, c=0, f;
vector<int> v[52];
int go(int k, int cnt) {
	if (v[k].size() == 0 || k == m+1) return 0;
	for (int a : v[k]) {
		if (a == m + 1 && v[k].size() == 1) return cnt + 1;
		if (a == m + 1) continue;
		if (v[a].size() == 0) cnt += 1;
		else cnt = go(a, cnt);
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		if (m == -1) f = i +1;
		v[m+1].push_back(i+1);
	}
	cin >> m;
	c = go(f, 0);
	cout << c << '\n';
}
