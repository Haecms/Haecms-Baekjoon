#include<iostream>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	int cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		if (s[i] >= 'a' && s[i] <= 'z') {
			if (s[i] == 'l' && s[i + 1] == 'j') {
				cnt++;
				i++;
			}
			else if (s[i] == 'd' && s[i + 1] == 'z' && s[i + 2] == '=') {
				cnt++;
				i+=2;
			}
			else if (s[i] == 'n' && s[i + 1] == 'j') {
				cnt++;
				i++;
			}
			else cnt++;
		}
	}
	cout << cnt;
}