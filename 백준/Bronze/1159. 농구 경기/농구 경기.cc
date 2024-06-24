#include <bits/stdc++.h>

using namespace std;
int people, cnt, alphabet[26];
string name, answer;
int main()
{
	cin >> people;
	
	for (int i = 0; i < people; i++) {
		cin >> name;
		alphabet[name[0] - 'a']++;
	}
	for (int i = 0; i < 26; i++) {
		if (alphabet[i] >= 5) cout << char('a' + i), cnt++;
	}
	if (!cnt) cout << "PREDAJA";
	
}