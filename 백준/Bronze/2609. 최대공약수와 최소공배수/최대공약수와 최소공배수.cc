#include<iostream>
#include<algorithm>
using namespace std;
int n, m, minNo, v;
int main() {
	cin >> n >> m;
	v = min(n, m);
	while (v > 0) {
		if (!(n % v) && !(m % v)) { minNo = v; break; }
		v--;
	}
	cout << minNo << "\n";
	v= min(n, m);
	while (v % n || v % m) {
		v += min(n, m);
	}
	cout << v << "\n";
	return 0;
}