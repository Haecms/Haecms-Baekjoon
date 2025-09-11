#include<iostream>
using namespace std;
int t, n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> t;
	while (t--) {
		long long ret = 0;
		cin >> n;
		while (n) {
			ret += n / 5;
			n /= 5;
		}
		cout << ret << "\n";
	}
	return 0;
}

