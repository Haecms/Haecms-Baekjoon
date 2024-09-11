#include<iostream>
using namespace std;
int a, b[2000004], c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> c;
		c > 0 ? b[c + 1000000] += 1 : b[abs(c)] += 1;
	}
	for (int i = 1000000; i >= 0; i--) {
		if (b[i] == 1) cout << -i << '\n';
	}
	for (int i = 1000001; i < 2000004; i++) {
		if (b[i] == 1) cout << i-1000000 << '\n';
	}
}