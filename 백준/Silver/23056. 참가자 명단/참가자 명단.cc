#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, m, grade, gradelist[11];
string name;
map<int, vector<pair<int, string>>> ma;
bool hello(pair<int, string> z, pair<int, string> y) {
	if (z.first == y.first) {
		if (z.second.size() == y.second.size()) {
			for (int i = 0; i < z.second.size(); i++) {
				if (z.second[i] != y.second[i]) return z.second[i] < y.second[i];
			}
		}
		return z.second.size() < y.second.size();
	}
	return z.first < y.first;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (true) {
		cin >> grade >> name;
		if (grade == 0 && name == "0") break;
		if (gradelist[grade] < m)
		{
			ma[grade % 2].push_back({ grade, name });
			gradelist[grade]++;
		}
	}
	for (auto &v : ma) {
		sort(v.second.begin(), v.second.end(), hello);
	}
	for (int i = 1; i >= 0; i--) {
		for (auto t : ma[i]) {
			cout << t.first << " " << t.second << "\n";
		}
	}
}