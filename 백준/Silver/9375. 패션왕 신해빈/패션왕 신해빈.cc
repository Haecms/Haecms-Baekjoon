#include <bits/stdc++.h>
using namespace std;
string cloth, section;
int n, m;
int main() {
	cin >> n;
	while (n--) {
		cin >> m;
		map<string, int> count;
		while (m--) {
			cin >> cloth >> section;
			count[section]++;
		}
		int ret = 1;
		for (auto c : count) {
			ret *= (c.second + 1);
		}
		cout << ret-1 << "\n";
	}
}
