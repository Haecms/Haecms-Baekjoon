#include<iostream>
#include<unordered_set>
#include<vector>
using namespace std;
int n, m;
string s;
unordered_set<string> us;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> s;
		us.insert(s);
	}
	while (m--) {
		cin >> s;
		int startIndex = 0;
		while (true) {
			auto endIndex = s.find(',', startIndex);
			if (endIndex != s.npos) {
				string a = s.substr(startIndex, endIndex - startIndex);
				if (us.find(a) != us.end()) us.erase(a);
				startIndex = endIndex + 1;
			}
			else {
				string a = s.substr(startIndex);
				if (us.find(a) != us.end()) us.erase(a);
				break;
			}
		}
		cout << us.size() << "\n";
	}
}
