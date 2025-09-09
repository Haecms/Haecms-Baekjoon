#include<iostream>
#include<string>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> s;
		if (s == "end") break;
		bool one = false;
		bool two = true;
		bool three = true;
		int cnt = 0;
		int cnt2_1 = 0, cnt2_2 = 0;
		char before = ' ';
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
				one = true;
				cnt2_1++;
				cnt2_2 = 0;
				if (cnt2_1 == 3) two = false;
			}
			else {
				cnt2_1 = 0;
				cnt2_2++;
				if (cnt2_2 == 3) two = false;
			}

			if (before == s[i]) {
				if (s[i] != 'e' && s[i] != 'o') {
					three = false;
				}
			}
			else cnt = 0;
			before = s[i];
		}
		if (one && two && three) cout << "<" << s << "> is acceptable.\n";
		else cout << "<" << s << "> is not acceptable.\n";
	}
	return 0;
}