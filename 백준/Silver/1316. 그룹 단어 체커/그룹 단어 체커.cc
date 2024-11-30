#include<iostream>
using namespace std;
int n, ret=0;
string s;
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
        char c[27] = {};
		char before_c = s[0];
		bool check = true;
		c[before_c - 'a'] = 1;
		for (int i = 1; i < s.size(); i++) {
			if (s[i] != before_c) {
				if (c[s[i] - 'a']) {
					check = false;
					break;
				}
				else {
					before_c = s[i];
					c[s[i] - 'a'] = 1;
				}
			}
		}
		if (check) ret++;
	}
	cout << ret << "\n";
}