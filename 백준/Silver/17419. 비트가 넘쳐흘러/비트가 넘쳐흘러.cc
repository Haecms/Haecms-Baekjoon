#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, cnt=0;
	long long a=0;
	string s, c_s;
	cin >> n >> s;
	bool flag = true;
	while (flag) {
		c_s = s;
		cnt++;
		for (int i = s.size() - 1; i >= 0; i--) {
			c_s[i] = c_s[i] == '1' ? '0' : '1';
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if (c_s[i] == '1') c_s[i] = '0';
			else {
				c_s[i] = '1';
				break;
			}
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if (c_s[i] != s[i]) c_s[i] = '0';
		}
		for (int i = s.size() - 1; i >= 0; i--) {
			if (c_s[i] == '1') {
				int index = i;
				while (index>=0) {
					if (s[index] == '1') {
						s[index] = '0';
						break;
					}
					else {
						s[index--] = '1';
					}
				}
			}
		}
		for (int i = 0; i < s.size(); i++) {
			if (s[i] == '1') break;
			flag = false;
		}
	}
	cout << cnt;
	
}