#include<iostream>
#include<string>
using namespace std;
int p;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	string s;
	getline(cin, s);
	while (true) {
		getline(cin, s);
		if (s.size() >= 16) break;
		if (s == "문제") p++;
		else if (!p) p += 2;
		else p--;
	}
	if (p) cout << "힝구" << "\n";
	else cout << "고무오리야 사랑해" << "\n";
	return 0;
}