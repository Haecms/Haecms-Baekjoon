#include <bits/stdc++.h>

using namespace std;
string s;
int main()
{
	getline(cin, s);
	
	for (int i = 0; i < s.size(); i++) {
		if (s[i] == ' ') {
			cout << " ";
			continue;
		}
		if (s[i] >= 'A' && s[i] <= 'Z') {
			if (s[i] + 13 < 'Z' + 1) { cout << char(s[i] + 13); }
			else { cout << char(s[i] - 13); }
		}
		else if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] + 13 < 'z' + 1) { cout << char(s[i] + 13); }
			else { cout << char(s[i] - 13); }
		}
		else { cout << s[i]; }
	}
}