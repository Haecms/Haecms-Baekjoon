#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, dp[204][204];
string a, b, c;

int go(int aIndex, int bIndex) {
	if (aIndex == a.size() && bIndex == b.size()) return 1;
	int &ret = dp[aIndex][bIndex];
	if (ret != -1) return ret;
	ret = 0;
	if (aIndex < a.size() && a[aIndex] == c[aIndex + bIndex]) ret = max(ret, go(aIndex + 1, bIndex));
	if (bIndex < b.size() && b[bIndex] == c[aIndex + bIndex]) ret = max(ret, go(aIndex, bIndex + 1));
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a >> b >> c;
		memset(dp, -1, sizeof(dp));
		if (go(0, 0)) {
			cout << "Data set " << i << ": yes\n";
		} else cout << "Data set " << i << ": no\n";
	}
	return 0;
}