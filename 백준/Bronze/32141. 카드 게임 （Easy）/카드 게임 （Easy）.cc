#include<iostream>
using namespace std;
int n, m, h;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> h;
		m -= h;
		if (m <= 0) {
			cout << i;
			return 0;
		}
	}
	cout << -1;
}
