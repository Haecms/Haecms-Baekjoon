#include<iostream>
#include<unordered_map>
using namespace std;
int n, m, a, ret, b;
unordered_map<int, int> um;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m; b = n + m;
	while (b--) cin >> a, um[a]++;
	for (auto i : um) if (i.second & 1) ret++;
	cout << ret << "\n";
	return 0;
}