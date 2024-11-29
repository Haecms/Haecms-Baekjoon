#include<iostream>
#include<string>
using namespace std;
int n, m, ret=0;
string s;
int main() {
	cin >> n >> m;
	cin.ignore();
	while (m--) {
		getline(cin, s);
		int point = 0;
		for (char c : s) {
			if (c >= 'A' && c <= 'Z') point+=4;
			else if (c == ' ') point+=1;
			else point+=2;
		}
		if (point <= n) ret++;
	}
	cout << ret << "\n";
	return 0;
}