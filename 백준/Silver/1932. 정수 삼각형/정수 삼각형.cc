#include<iostream>
#include<algorithm>
using namespace std;
int n, a[504][504];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j <= i; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = n; i >= 0; i--) {
		for (int j = 0; j < i; j++) {
			a[i - 1][j] += max(a[i][j], a[i][j + 1]);
		}
	}
	cout << a[0][0] << "\n";
	return 0;
}