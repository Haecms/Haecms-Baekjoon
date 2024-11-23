#include<iostream>
#include<vector>
using namespace std;
int n, m, k, s, e;
vector<int> v[200001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> k >> s >> e;
		if (v[k].size()) {
			if (v[k].back() <= s) {
				v[k].push_back(e);
				cout << "YES" << "\n";
			}
			else cout << "NO" << "\n";
		}
		else {
			v[k].push_back(e);
			cout << "YES" << "\n";
		}
	}
}
