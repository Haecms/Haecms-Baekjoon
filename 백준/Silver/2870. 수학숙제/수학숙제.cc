#include<bits/stdc++.h>
using namespace std;
int n;
string s;
vector<string> v;
bool smp(string a, string b) {
	if (a.size() != b.size()) return a.size() < b.size();
	for (int i = 0; i < a.size(); i++) {
		if ((int)a[i] != int(b[i])) return (int)a[i] < (int)b[i];
	}
}
int main()
{
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;
		string m;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'a' && s[i] <= 'z') { 
				if (m.size()) v.push_back(m);
				m = "";
			}
			else {
				if (m.size()) { m += s[i]; }
				else { m = s[i]; }
			}
		}
		if (m.size()) v.push_back(m);
	}
	for (int i = 0; i < v.size(); i++) {
		while (v[i][0] == '0' && v[i].size() != 1) v[i].erase(0, 1);
	}
	sort(v.begin(), v.end(), smp);
	for (string a : v) {
		cout << a << '\n';
	}
	return 0;
}