#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n,x,a,b,c,d;
vector<pair<int, int>> m1;
vector<pair<int, int>> m2;
vector<pair<int, int>> m3;
vector<pair<int, int>> m4;
string s = "0000";
bool hello(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
int main() {
	cin >> n;
	while(n--) {
		cin >> x >> a >> b >> c >> d;
		m1.push_back({ a,x });
		m2.push_back({ b,x });
		m3.push_back({ c,x });
		m4.push_back({ d,x });
	}
	sort(m1.begin(), m1.end(), hello);
	sort(m2.begin(), m2.end(), hello);
	sort(m3.begin(), m3.end(), hello);
	sort(m4.begin(), m4.end(), hello);
	for (auto m : m1) {
		bool check = true;
		for (int i = 0; i < 4; i++) {
			if ((s[i] - '0') == m.second) {
				check = false;
			}
		}
		if (check) {
			s[0] = m.second + '0';
			cout << m.second << " ";
			break;
		}
	}
	for (auto m : m2) {
		bool check = true;
		for (int i = 0; i < 4; i++) {
			if ((s[i] - '0') == m.second) {
				check = false;
			}
		}
		if (check) {
			s[1] = m.second + '0';
			cout << m.second << " ";
			break;
		}
	}
	for (auto m : m3) {
		bool check = true;
		for (int i = 0; i < 4; i++) {
			if ((s[i] - '0') == m.second) {
				check = false;
			}
		}
		if (check) {
			s[2] = m.second + '0';
			cout << m.second << " ";
			break;
		}
	}
	for (auto m : m4) {
		bool check = true;
		for (int i = 0; i < 4; i++) {
			if ((s[i] - '0') == m.second) {
				check = false;
			}
		}
		if (check) {
			s[3] = m.second + '0';
			cout << m.second;
			break;
		}
	}
}