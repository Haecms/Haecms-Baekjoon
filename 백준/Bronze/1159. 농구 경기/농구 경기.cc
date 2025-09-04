#include<iostream>
using namespace std;
int n, a[26], flag;
string s;
int main() {
	cin >> n;
	while (n--) {
		cin >> s;
		a[s[0] - 'a']++;
		if (a[s[0] - 'a'] >= 5) flag = 1;
	}
	if (flag) {
		for (int i = 0; i < 26; i++) {
			if (a[i] >= 5) cout << (char)(i + 'a');
		}
	}
	else cout << "PREDAJA";
	return 0;
}