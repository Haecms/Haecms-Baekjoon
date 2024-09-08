#include<iostream>
using namespace std;
int c[200002], g[200002];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a, b, ret=0, d, e, f;
	cin >> a;
	for (long long i = 1; i <= a; i++) { cin >> c[i]; ret += c[i]; g[i] = 0; }
	cout << ret << '\n';
	cin >> b;
	while (b--) {
		cin >> d >> e;
		if (d == 1) {
			cin >> f;
			if(!g[e]) ret += f-c[e];
			c[e] = f;
		}
		else {
			g[e] ^= 1;
			ret += g[e] ? -c[e] : c[e];
		}
		cout << ret << '\n';
	}
	return 0;
}
