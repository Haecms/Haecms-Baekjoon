#include<iostream>
#include<algorithm>
using namespace std;

int n, health[104], happy[104], dp[3000000];

int go(int idx, int hp, int pleasure, int visited) {
	if (hp < 1) return -999999;
	int &ret = dp[visited];
	if (ret) return ret;
	ret = pleasure;
	for (int i = idx+1; i <= n; i++) {
		if (visited & (1<<i)) continue;
		ret = max(ret, go(i, hp - health[i], pleasure + happy[i], visited | (1<<i)));
	}
	return ret;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 1; i <= n; i++) cin >> health[i];
	for (int i = 1; i <= n; i++) cin >> happy[i];
	cout << go(0, 100, 0, 0) << "\n";
	return 0;
}