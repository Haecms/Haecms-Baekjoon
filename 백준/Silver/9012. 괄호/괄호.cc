#include<iostream>
using namespace std;
int n;
string s;
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
		int l = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '(') l++;
			else l--;
			if (l < 0) { cout << "NO" << '\n'; l = 100; break; }
		}
		if (l == 0) cout << "YES" << '\n';
		else if (l != 100) cout << "NO" << '\n';
	}
}