#include<iostream>
using namespace std;
int n, q, a, b;
string s;
int main() {
	cin >> n >> s >> q;
	while (q--) {
		cin >> a >> b;
		string s_s = "";
		for (int i = a - 1; i < b; i++) 
			s_s += string(1, s[i]);
		
		int splitIndex = 1;
		int realCnt = 0;
		int splitRange = s_s.size() - 1;
		while (splitIndex <= splitRange) {
			int cnt = 0;
			for (int i = 0; i < splitIndex; i++) {
				if (splitIndex + i >= s_s.size()) break;
				if (s_s[splitIndex - i - 1] == s_s[splitIndex + i]) cnt++;
			}
			realCnt = max(cnt, realCnt);
			splitIndex++;
		}
		cout << realCnt << "\n";
	}
	return 0;
}