#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;

int n;
unordered_map<string, int>um;
string s;
vector<string> v;

bool cmp(string s1, string s2) {
	if (s1.size() != s2.size()) return s1.size() < s2.size();
	return s1 < s2;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);

	cin >> n;
	while (n--) { cin >> s; um[s]++; }

	for (auto ma : um) { v.push_back(ma.first); }
	sort(v.begin(), v.end(), cmp);

	for (string vs : v) cout << vs << "\n";

	return 0;
}