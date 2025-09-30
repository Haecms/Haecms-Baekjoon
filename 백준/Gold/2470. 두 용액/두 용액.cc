#include<iostream>
#include<vector>
#include<algorithm>
#include<math.h>
using namespace std;
int n, a,miIdx = 0, plIdx = 0, minSum = 2000000001;
vector<int> mi, pl;
pair<int, int> ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a < 0) mi.push_back(a);
		else pl.push_back(a);
	}
	sort(mi.begin(), mi.end(),greater<>());
	sort(pl.begin(), pl.end());
	if (!mi.size()) cout << pl[0] << " " << pl[1];
	else if (!pl.size()) cout << mi[1] << " " << mi[0];
	else if (pl.size() == 1 && mi.size() == 1) cout << mi[0] << " " << pl[0];
	else {
		while (true) {
			int	sum = abs(mi[miIdx] + pl[plIdx]);
			if (sum < minSum) {
				ret.first = mi[miIdx];
				ret.second = pl[plIdx];
				minSum = sum;
			}
			if (miIdx+1 < mi.size() && plIdx+1 < pl.size()) {
				if (abs(mi[miIdx + 1] + pl[plIdx]) >= abs(mi[miIdx] + pl[plIdx + 1])) {
					plIdx++;
					continue;
				}
				else {
					miIdx++;
					continue;
				}
			}
			else break;
		}
		if (mi.size() > 1) {
			if (abs(mi[0] + mi[1]) < minSum) {
				ret.first = mi[1];
				ret.second = mi[0];
				minSum = abs(mi[0] + mi[1]);
			}
		}
		if (pl.size() > 1) {
			if (abs(pl[0] + pl[1]) < minSum) {
				ret.first = pl[0];
				ret.second = pl[1];
				minSum = abs(pl[0] + pl[1]);
			}
		}
		if (miIdx + 1 == mi.size()) {
			for (int i = plIdx; i < pl.size(); i++) {
				if (minSum > abs(mi[miIdx] + pl[i])) {
					ret.first = mi[miIdx];
					ret.second = pl[i];
					minSum = abs(mi[miIdx] + pl[i]);
				}
			}
		}
		else if (plIdx + 1 == pl.size()) {
			for (int i = miIdx; i < mi.size(); i++) {
				if (minSum > abs(mi[i] + pl[plIdx])) {
					ret.first = mi[i];
					ret.second = pl[plIdx];
					minSum = abs(mi[i] + pl[plIdx]);
				}
			}
		}
		cout << ret.first << " " << ret.second;
	}
	return 0;
}