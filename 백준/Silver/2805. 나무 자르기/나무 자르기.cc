#include<iostream>
#include<vector>
using namespace std;
int n, m, vv, ret;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> vv, v.push_back(vv);
	int lv = 0, rv=2000000000;
	while (lv <= rv) {
		long long middle = (lv + rv) / 2;
		long long sum = 0;
		for (int a : v) {
			if (a > middle) sum += a - middle;
		}
		if (m <= sum) {
			ret = middle;
			lv = middle + 1;
		}
		else rv = middle - 1;
	}
	cout << ret << "\n";
	return 0;
}