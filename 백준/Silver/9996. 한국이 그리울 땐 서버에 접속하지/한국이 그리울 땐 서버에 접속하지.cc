#include <bits/stdc++.h>
using namespace std;
string s, ori_s, pre, suf;
int n;

int main()
{
	cin >> n;
	cin >> ori_s;
	int pos = ori_s.find('*');
	pre = ori_s.substr(0, pos);
	suf = ori_s.substr(pos + 1);
	for (int i = 0; i < n; i++) {
		cin >> s;
		if (pre.size() + suf.size() > s.size()) cout << "NE\n";
		else {
			if (pre == s.substr(0, pre.size()) && suf == s.substr(s.size() - suf.size())) cout << "DA\n";
			else cout << "NE\n";
		}
	}
}