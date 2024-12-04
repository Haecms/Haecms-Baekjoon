#include<iostream>
#include<string>
using namespace std;
string s;
void setData(int startIndex, int endIndex) {
	while (startIndex < endIndex) {
		char temp = s[endIndex];
		s[endIndex--] = s[startIndex];
		s[startIndex++] = temp;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	getline(cin, s);
	int curPos = 0;
	while (true) {
		int arrowPos1 = s.find('<', curPos);
		int arrowPos2 = s.find('>', arrowPos1);
		int spacePos = s.find(' ', curPos);
		if (arrowPos1 == spacePos) {
			setData(curPos, s.size() -1);
			break;
		}
		arrowPos1 = arrowPos1 == -1 ? 2000000 : arrowPos1;
		spacePos = spacePos == -1 ? 2000000 : spacePos;
		if (arrowPos1 > spacePos) {
			setData(curPos, spacePos - 1);
			curPos = spacePos + 1;
		}
		else {
			if (curPos == arrowPos1) {
				curPos = arrowPos2 + 1;
			}
			else {
				setData(curPos, arrowPos1 - 1);
				curPos = arrowPos1;
			}
		}
	}
	cout << s;
}