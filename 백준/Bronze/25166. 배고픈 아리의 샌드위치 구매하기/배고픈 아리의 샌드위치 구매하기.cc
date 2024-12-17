#include<iostream>
#include<vector>
using namespace std;
int n, m;
vector<int> v;
int main() {
	cin >> n >> m;
	for (int i = 9; i >= 0; i--) {
		if (n >= 1 << i) n -= 1 << i;
		if (m & 1 << i) v.push_back(1 << i);
	}
	if (!n) cout << "No thanks" << "\n";
	else if (n <= m) {
		for (int i : v) if (n >= i) n-=i;
		if (!n) cout << "Thanks" << "\n";
		else cout << "Impossible" << "\n";
	}
	else cout << "Impossible" << "\n";
	return 0;
}