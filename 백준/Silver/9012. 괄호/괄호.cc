#include<iostream>
using namespace std;
int n;
string s;
int main() {
	cin >> n;
	while (n--) {
		cin >> s; int l = 0;
		for (char a : s) {
			a == '(' ? l++ : l--;
			if (l < 0) { cout << "NO"; l = 100; break; }
		}
		l == 0 ? cout << "YES\n" : l != 100 ? cout << "NO\n" : cout << '\n';
	}
}