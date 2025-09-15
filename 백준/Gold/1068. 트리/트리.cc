#include<iostream>
#include<vector>
using namespace std;
vector<int> v[54];
int n, a, root;
int go(int cur) {
	if (cur == a) return 0;
	if (!v[cur].size()) return 1;
	int cnt = 0;
	for (auto vv : v[cur]) {
		if (vv == a && v[cur].size() == 1) return 1;
		cnt += go(vv);
	}
	return cnt;
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (a != -1) v[a].push_back(i);
		else root = i;
	}
	cin >> a;
	cout << go(root) << "\n";
	return 0;
}