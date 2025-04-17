#include<iostream>
using namespace std;
int n, a[26];
string s;
int main() {
	cin >> s;
	for (int i = 0; i < 26; i++) a[i] = -1;
	for (int i = 0; i < s.size(); i++) {
		if (a[s[i] - 'a'] == -1) a[s[i] - 'a'] = i;
	}
	
	for (int i = 0; i < 26; i++) cout << a[i] << " "; 
	return 0;
}