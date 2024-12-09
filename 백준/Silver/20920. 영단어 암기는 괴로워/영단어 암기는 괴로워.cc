#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<vector>
using namespace std;
int n, m;
string s;
unordered_map<string, int> um;
bool cmp(pair<string, int> a, pair<string, int> b) {
	if (a.second == b.second) {
		if (a.first.size() == b.first.size()) {
			return a.first < b.first;
		}
		else {
			return a.first.size() > b.first.size();
		}
	}
	else {
		return a.second > b.second;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (n--) {
		cin >> s;
		if (s.size() >= m) um[s]++;
	}
	vector<pair<string, int>> v(um.begin(), um.end());
	sort(v.begin(), v.end(), cmp);
	for (auto s : v) {
		cout << s.first << "\n";
	}
}