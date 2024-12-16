#include<iostream>
#include<algorithm>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	sort(s.begin(), s.end(), greater<char>());
	if (s[s.size() - 1] != '0') cout << -1 << "\n";
	else {
		int cnt = 0;
		for (int i = 0; i < s.size() - 1; i++) cnt += s[i] - '0';
		if (cnt % 3) cout << -1 << "\n";
		else for (char c : s) cout << c;
	}
	return 0;
}