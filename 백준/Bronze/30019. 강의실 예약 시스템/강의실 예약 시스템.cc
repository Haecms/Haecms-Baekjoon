#include<iostream>
#include<map>
using namespace std;
int n, m, k, s, e;
map<int, int> ma;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> k >> s >> e;
		if (ma[k]) {
			if (ma[k] <= s) {
				ma[k] = e;
				cout << "YES" << "\n";
			}
			else cout << "NO" << "\n";
		}
		else {
			ma[k] = e;
			cout << "YES" << "\n";
		}
	}
}
