#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
	int n, a;
	string s;
	unordered_map<int, vector<string>> ma;
	cin >> n;
	while (n--) {
		cin >> a >> s;
		ma[a].push_back(s);
	}
	vector<pair<int, vector<string>>> v(ma.begin(), ma.end());
	sort(v.begin(), v.end());
	for (auto v1 : v) {
		for (string s : v1.second) {
			cout << v1.first << " " << s << "\n";
		}
	}
	return 0;
}