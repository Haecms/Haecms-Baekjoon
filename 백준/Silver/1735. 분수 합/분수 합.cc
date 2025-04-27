#include<iostream>
using namespace std;
typedef long long ll;
int main() {
	ll a, b, c, d, e,f;
	cin >> a >> b >> c >> d;
	e = a * d + b * c;
	f = b * d;
	ll ee = e, ff = f;
	while (ee % ff) {
		ll g = ee % ff;
		ee = ff;
		ff = g;
	}
	cout << e / ff << " " << f / ff << "\n";
	return 0;
}