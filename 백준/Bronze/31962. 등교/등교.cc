#include<iostream>
using namespace std;
int n, m, s, t, maxs = -1;
int main() {
	cin >> n >> m;
	while (n--) {
		cin >> s >> t;
		if (s + t <= m) {
			maxs = max(maxs, s);
		}
	}
	cout << maxs << "\n";
}