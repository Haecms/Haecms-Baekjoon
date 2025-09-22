#include<iostream>
using namespace std;
int t, a[1004],n;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);cout.tie(0);
	cin >> t;
	for (int i = 0; i < 1004; i++) {
		if (n < 17) a[i]++;
		else if (n == 24) { n = 0; continue; };
		n++;
	}
	while (t--) {
		cin >> n;
		cout << (a[n] ? "ONLINE" : "OFFLINE") << "\n";
	}
	return 0;
}