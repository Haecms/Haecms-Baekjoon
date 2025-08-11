#include<iostream>
using namespace std;
int n, l,r,m,ll,rl, cnt;
pair<int, int> heart, important;
char c[1004][1004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> c[i][j];
			if (c[i][j] == '*' && !heart.first) heart.first = i+1, heart.second = j;
		}
	}
	while (--cnt + heart.second >=0 && c[heart.first][heart.second + cnt] == '*') { }
	l = -(cnt + 1);
	cnt = 0;
	while (++cnt + heart.second < n && c[heart.first][heart.second + cnt] == '*') {	}
	r = cnt - 1;
	cnt = 0;
	while (++cnt + heart.first < n && c[heart.first+cnt][heart.second] == '*') { }
	m = cnt - 1;
	cnt = 0;
	while (heart.second - 1 >= 0 && ++cnt + heart.first < n && c[heart.first + m + cnt][heart.second-1] == '*') {}
	ll = cnt - 1;
	cnt = 0;
	while (heart.second + 1 < n && ++cnt + heart.first < n && c[heart.first + m + cnt][heart.second+1] == '*') {}
	rl = cnt - 1;
	cnt = 0;
	cout << heart.first+1 << " " << heart.second+1 << "\n";
	cout << l << " " << r << " " << m << " " << ll << " " << rl << "\n";
	return 0;
}