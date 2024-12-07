#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, m;
	vector<string> v1;
	vector<string> v2;
	string s;
	cin >> n >> m;
	while (n--) {
		cin >> s;
		v1.push_back(s);
	}
	sort(v1.begin(), v1.end());
	while (m--) {
		cin >> s;
		if (binary_search(v1.begin(), v1.end(), s)) {
			v2.push_back(s);
		}
	}
	sort(v2.begin(), v2.end());
	cout << v2.size() << "\n";
	for (string st : v2) cout << st << "\n";
	return 0;
}