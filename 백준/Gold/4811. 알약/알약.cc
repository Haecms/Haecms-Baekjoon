#include<iostream>
#include<memory.h>
using namespace std;
typedef long long ll;
ll n, m, dp[64][64][64];

ll go(int idx, int W, int H) {
	if (idx == m * 2) return 1;
	ll& ret = dp[idx][W][H];
	if (ret) return ret;
	if (W > 0) ret += go(idx + 1, W - 1, H + 1);
	if(H > 0) ret += go(idx + 1, W, H - 1);
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> m;
		if (!m) break;
		memset(dp, 0, sizeof(dp));
		cout << go(1, m-1, 1) << "\n";
	}
	return 0;
}