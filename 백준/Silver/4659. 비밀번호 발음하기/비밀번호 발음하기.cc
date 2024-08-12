#include<bits/stdc++.h>
using namespace std;
string s;
map<char, int> moum = {
	{'a', 1}, {'b', 0}, {'c', 0}, {'d', 0},	{'e', 1},
	{'f', 0}, {'g', 0}, {'h', 0}, {'i', 1}, {'j', 0},
	{'k', 0}, {'l', 0}, {'m', 0}, {'n', 0}, {'o', 1},
	{'p', 0}, {'q', 0}, {'r', 0}, {'s', 0}, {'t', 0},
	{'u', 1}, {'v', 0}, {'w', 0}, {'x', 0}, {'y', 0},
	{'z', 0}
};
int main()
{
	while (true) {
		cin >> s;
		if (s == "end") break;
		bool flag1 = false;
		bool flag2 = true;
		for (char a : s) {
			if (moum[a]) { flag1 = true; break; }
		}
		stack<char> munjayeol;
		for (char a : s) {
			if (munjayeol.size() != 0) 
			{
				if (munjayeol.top() == a) {
					if (a != 'e' && a != 'o') { flag2 = false; break; }
				}
				if (munjayeol.size() > 1) {
					if (moum[munjayeol.top()] == moum[a]) {
						char n = munjayeol.top();
						munjayeol.pop();
						if (moum[munjayeol.top()] == moum[a]) { flag2 = false; break; }
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