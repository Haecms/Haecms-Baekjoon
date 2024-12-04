#include<iostream>
#include<string>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	string s;
	getline(cin, s);
	int curPos = 0;
	string cs = "";
	while (true) {
		int arrowPos1 = s.find('<', curPos) == -1 ? 200000 : s.find('<', curPos);
		int arrowPos2 = s.find('>', curPos) == -1 ? 200000 : s.find('>', curPos);
		int spacePos  = s.find(' ', curPos) == -1 ? 200000 : s.find(' ', curPos);
		if (arrowPos1 == spacePos) {
			for (int i = s.size() - 1; i >= curPos; i--) {
				cs += string(1, s[i]);
			}
			break;
		}
		if (arrowPos1 > spacePos) {
			for (int i = spacePos - 1; i >= curPos; i--) {
				cs += string(1, s[i]);
			}
			cs += " ";
			curPos = spacePos + 1;
		}
		else {
			if (curPos == arrowPos1) {
				for (int i = arrowPos1; i <= arrowPos2; i++) {
					cs += string(1, s[i]);
				}
				curPos = arrowPos2 + 1;
			}
			else {
				for (int i = arrowPos1 - 1; i >= curPos; i--) {
					cs += string(1, s[i]);
				}
				curPos = arrowPos1;
			}
		}
	}
	cout << cs;
}