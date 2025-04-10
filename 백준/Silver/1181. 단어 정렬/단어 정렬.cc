#include<iostream>
#include<unordered_set>
#include<vector>
#include<algorithm>
using namespace std;
int n;
string s;
unordered_set<string> us;
bool cmp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	return a < b;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> s;
		us.insert(s);
	}
	vector<string> v(us.begin(), us.end());
	sort(v.begin(), v.end(), cmp);
	for (auto a : v) cout << a << "\n";
}