#include<iostream>
#include<unordered_map>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m, a, ret = 0;
	unordered_map<int, int> ma;
	cin >> n >> m;
	for (int i = 0; i < n + m; i++) {
		cin >> a;
		ma[a]++;
	}
	for (auto m : ma) {
		if (m.second == 1) ret++;
	}
	cout << ret << "\n";
}