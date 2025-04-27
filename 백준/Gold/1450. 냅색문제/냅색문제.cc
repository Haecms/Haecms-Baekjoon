#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a[31], cnt;
vector<int> v1, v2;

void go(int here, int nn, vector<int> &v, int val) {
	if (here > nn) {
		v.push_back(val);
		return;
	}
	if (val + a[here] <= m) go(here + 1, nn, v, val + a[here]);
	go(here + 1, nn , v, val);
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	go(0, n / 2 - 1, v1, 0);
	go(n / 2, n - 1, v2, 0);
	sort(v1.begin(), v1.end());
	sort(v2.begin(), v2.end());
	for (int v : v1) {
		if (m - v >= 0) cnt += (int)(upper_bound(v2.begin(), v2.end(), m - v) - v2.begin());
	}
	cout << cnt << "\n";
	return 0;
}