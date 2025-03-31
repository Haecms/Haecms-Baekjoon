#include<iostream>
#include<memory.h>
using namespace std;
typedef long long ll;
ll n, m, dp[64][64];

ll go(int W, int H) {
	if (!W && !H) return 1;
	ll& ret = dp[W][H];
	if (ret) return ret;
	if (W > 0) ret += go(W - 1, H + 1);
	if (H > 0) ret += go(W, H - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> m;
		if (!m) break;
		memset(dp, 0, sizeof(dp));
		cout << go(m-1, 1) << "\n";
	}
	return 0;
}