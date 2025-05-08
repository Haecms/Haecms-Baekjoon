#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, b, a, retTime = 1e9, retHeight;
vector<int> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> b;
	for (int i = 0; i < n * m; i++) cin >> a, v.push_back(a);
	sort(v.begin(), v.end(), greater<int>());
	int rv = 256;
	while (rv >= 0) {
		int copy_cnt = b;
		int ttime = 0;
		for (int vv : v) {
			if (vv > rv) {
				copy_cnt += (vv - rv);
				ttime += (2 * (vv - rv));
			}
			else if (vv < rv) {
				copy_cnt -= (rv - vv);
				ttime += (rv - vv);
			}
			if (copy_cnt < 0) break;
		}
		if (copy_cnt < 0) { rv--; continue; }
		if (retTime > ttime) {
			retTime = ttime;
			retHeight = rv;
		}
		rv--;
	}
	cout << retTime << " " << retHeight << "\n";
	return 0;
}