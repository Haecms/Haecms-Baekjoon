#include<iostream>
using namespace std;
long long n, m, p, t, x;
int main() {
	cin >> n >> m >> p;
	for (int i = 0; i < n; i++) {
		cin >> t >> x;
		if (t <= m) {
			if (p < x) {
				cout << "YES";
				return 0;
			}
		}
	}
	cout << "NO";
	return 0;
}