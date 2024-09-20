#include<iostream>
using namespace std;
int n, b, c, a[1000004];
long long cnt = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	cin >> b >> c;
	for (int i = 0; i < n; i++) {
		if (a[i] - b <= 0) cnt += 1;
		else cnt += (a[i] - b) % c != 0 ? (a[i] - b) / c + 2 : (a[i] - b) / c + 1;
	}
	cout << cnt;
	return 0;
}