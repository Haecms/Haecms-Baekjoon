#include<iostream>
using namespace std;
int c[200002], g[200002];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long a, b, ret=0, d, e, f;
	cin >> a;
	for (long long i = 1; i <= a; i++) { cin >> c[i]; g[i] = 0; ret += c[i]; }
	cin >> b;
	cout << ret << '\n';
	while (b--) {
		cin >> d;
		d == 1 ? cin >> e >> f : cin >> e;
		if (d == 1) {
			if(!g[e]) ret += f-c[e];
			c[e] = f;
		}
		else {
			if (g[e]) ret += c[e];
			else ret -= c[e];
			g[e] = g[e] ? 0 : 1;
		}
		cout << ret << '\n';
	}
	return 0;
}
