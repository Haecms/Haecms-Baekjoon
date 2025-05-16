#include<iostream>
#include<algorithm>
using namespace std;
int  n, m, li, a[100004], sum, ret=1e9;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		sum += a[i];
		while (sum >= m) {
			ret = min(ret, i - li + 1);
			sum -= a[li++];
		}
	}
	if (ret == 1e9) ret = 0;
	cout << ret << "\n";
	return 0;
}