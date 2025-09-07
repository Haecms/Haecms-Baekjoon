#include<iostream>
using namespace std;
string s;
char c[26];
int cnt, idx=-1;
int main() {
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		c[s[i]-'A']++;
	}
	for (int i = 0; i < 26; i++) {
		if (c[i] % 2 == 1) cnt++, idx = i;
	}
	if (cnt > 1) cout << "I'm Sorry Hansoo";
	else {
		for (int i = 0; i < 26; i++) {
			for (int j = 0; j < c[i] / 2; j++) {
				cout << char(i + 'A');
			}
		}
		if(idx >= 0) cout << char(idx + 'A');
		for (int i = 25; i >= 0; i--) {
			for (int j = 0; j < c[i] / 2; j++) {
				cout << char(i + 'A');
			}
		}
	}
	return 0;
}