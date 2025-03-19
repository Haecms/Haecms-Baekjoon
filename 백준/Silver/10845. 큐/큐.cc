#include<iostream>
#include<list>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, val;
	string s;
	list<int> l;
	cin >> n;
	while (n--) {
		cin >> s;
		switch (s[1]) {
		case 'u': cin >> val, l.push_back(val); break;
		case 'r':
			if (l.size()) cout << l.front() << "\n";
			else cout << -1 << "\n";
			break;

		case 'a':
			if (l.size()) cout << l.back() << "\n";
			else cout << -1 << "\n";
			break;
		case 'o': 
			if (l.size()) cout << l.front() << "\n", l.pop_front();
			else cout << -1 << "\n";
			break;
		case 'i': cout << l.size() << "\n"; break;
		case 'm': cout << (bool(l.size()) ^ 1) << "\n"; break;
		}
	}
	return 0;
}