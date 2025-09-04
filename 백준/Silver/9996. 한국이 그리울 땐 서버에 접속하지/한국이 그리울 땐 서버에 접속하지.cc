#include<iostream>
using namespace std;
int n;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s;
	int starIdx = s.find('*');
	string before = s.substr(0, starIdx);
	string after = s.substr(starIdx+1);
	while (n--) {
		cin >> s;
		if (s.size() < before.size() + after.size()) { cout << "NE\n"; continue; }
		string sBefore = s.substr(0, before.size());
		string sAfter = s.substr(s.size() - after.size());
		if (sBefore == before && sAfter == after) cout << "DA\n";
		else cout << "NE\n";
	}
	return 0;
}