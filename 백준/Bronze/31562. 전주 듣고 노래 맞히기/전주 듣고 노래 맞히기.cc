#include<iostream>
#include<map>
#include<vector>
using namespace std;
long long n, m;
string s, t;
char a, b, c;
map<string, vector<string>> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> t >> s;
		char s_s[8];
		char q;
		for (int i = 0; i < 7; i++) {
			cin >> q;
			s_s[i]= q;
		}
		string hello = string(1, s_s[0]) + string(1, s_s[1]) + string(1, s_s[2]); // 개별 문자를 string으로 변환 아스키코드로 계산됐음
		v[hello].push_back(s);
	}
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		string hello = string(1, a) + string(1, b) + string(1, c);
		if (v[hello].size() > 1) {
			cout << "?\n";
		}
		else if (v[hello].size() == 0) {
			cout << "!\n";
		}
		else {
			cout << v[hello][0] << "\n";
		}
	}
	return 0;
}