#include<iostream>
using namespace std;
int n, m, a, ret=0, cnt=0;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ret += a;
		if (ret < 0) ret = 0;
		if (ret >= m) cnt++;
	}
	cout << cnt << "\n";
}
