#include<bits/stdc++.h>
using namespace std;
string s;
bool isMoum(char a) { return a == 'a' || a == 'i' || a == 'e' || a == 'o' || a == 'u'; }
int main()
{
	while (true) {
		cin >> s;
		if (s == "end") break;
		bool flag1 = false;
		bool flag2 = true;
		for (char a : s) {
			if (isMoum(a)) { flag1 = true; break; }
		}
		stack<char> munjayeol;
		for (char a : s) {
			if (munjayeol.size() != 0) 
			{
				if (munjayeol.top() == a) {
					if (a != 'e' && a != 'o') { flag2 = false; break; }
				}
				if (munjayeol.size() > 1) {
					if (isMoum(munjayeol.top()) == isMoum(a)) {
						char n = munjayeol.top();
						munjayeol.pop();
						if (isMoum(munjayeol.top()) == isMoum(a)) { flag2 = false; break; }
						else { munjayeol.push(n); }
					}
				}
			}
			munjayeol.push(a);
		}
		if (!flag1 || !flag2) { cout << "<" << s << ">" << " is not acceptable.\n"; }
		else { cout << "<" << s << ">" << " is acceptable.\n"; }
	}
}