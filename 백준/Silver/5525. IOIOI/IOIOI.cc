#include<iostream>
using namespace std;
int t, n, ret, cnt, startFlag;
char c, beforeC;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> t >> n;
	for (int i = 1; i <= n; i++) {
		cin >> c;
		if (c == 'I') {
			if (!startFlag) startFlag = i;
			else {
				if (beforeC != c) cnt++;
				else {
					if (cnt - t >= 0) ret += cnt - t + 1;
					startFlag = i;
					cnt = 0;
				}
			}
		}
		else {
			if (beforeC == c) {
				if (cnt - t >= 0) ret += cnt - t + 1;
				startFlag = 0;
				cnt = 0;
			}
		}
		beforeC = c;
	}
	if (cnt - t >= 0) ret += cnt - t + 1;
	cout << ret << "\n";
}