#include<iostream>
using namespace std;
int n, q, a, b;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> s >> q;
	while (q--) {
		cin >> a >> b;
		string s_s = "";
		for (int i = a - 1; i < b; i++) {
			s_s += string(1, s[i]);
		}
		int splitIndex = 1;
		int realCnt = 0;
		int splitRange = s_s.size() - 1;
		while (splitIndex <= splitRange) {
			int cnt = 0;
			for (int i = 0; i < splitIndex; i++) {
				if (splitIndex + i >= s_s.size()) break;
				int before = s_s[splitIndex - i - 1];
				int after = s_s[splitIndex + i];
				if (before == after) cnt++;
			}
			realCnt = max(cnt, realCnt);
			splitIndex++;
		}
		cout << realCnt << "\n";
	}
}