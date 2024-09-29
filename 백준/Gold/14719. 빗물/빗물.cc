#include<iostream>
#include<vector>
using namespace std;
int n, m, b, a[504][504], ret = 0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> b;
		for (int j = 1; j <= b; j++) {
			a[n-j][i] = 1;
		}
	}
	for (int i = 0; i < n; i++) {
		int cnt = 0;
		vector<pair<int, int>> v;
		for (int j = 0; j < m; j++) {
			if (a[i][j]) {
				cnt++;
				if (v.size() == 2) {
					v.pop_back();
					v.push_back({ i,j });
				} else v.push_back({ i,j });
			}
		}
		if (v.size() == 2) {
			ret += v[1].second - v[0].second + 1 - cnt;
		}
	}
	cout << ret << "\n";
}

