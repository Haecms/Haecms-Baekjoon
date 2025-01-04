#include<iostream>
using namespace std;
string s;
int alphabet[100];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i <	s.size(); i++) {
		if (s[i] >= 97) alphabet[s[i] - 32] += 1;
		else alphabet[s[i]] += 1;
	}
	int maxc = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (alphabet[i] > maxc) maxc = alphabet[i];
	}
	int cnt = 0;
	char ret = 0;
	for (int i = 'A'; i <= 'Z'; i++) {
		if (alphabet[i] == maxc) {
			cnt++;
			ret = i;
		}
	}
	if (cnt > 1) cout << "?";
	else cout << ret ;
}