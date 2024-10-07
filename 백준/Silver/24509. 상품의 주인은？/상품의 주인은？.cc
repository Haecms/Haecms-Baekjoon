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
bool check(int index, pair<int,int> e) {
	for (int i = 0; i < 4; i++) {
		if ((s[i] - '0') == e.second) {
			return false;
		}
	}
	s[index] = e.second + '0';
	cout << e.second << " ";
	return true;
}
int main() {
	cin >> n;
	while(n--) {
		cin >> x >> a >> b >> c >> d;
		if (m1.size() > 3) {
			if (a > m1[3].first) {
				m1.pop_back();
				m1.push_back({ a, x });
				sort(m1.begin(), m1.end(), hello);
			}
			else if (a == m1[3].first && x < m1[3].second) {
				m1.pop_back();
				m1.push_back({ a, x });
				sort(m1.begin(), m1.end(), hello);
			}
		}
		else {
			m1.push_back({ a, x });
			sort(m1.begin(), m1.end(), hello);
		}
		if (m2.size() > 3) {
			if (b > m2[3].first) {
				m2.pop_back();
				m2.push_back({ b, x });
				sort(m2.begin(), m2.end(), hello);
			}
			else if (b == m2[3].first && x < m2[3].second) {
				m2.pop_back();
				m2.push_back({ b, x });
				sort(m2.begin(), m2.end(), hello);
			}
		}
		else {
			m2.push_back({ b, x });
			sort(m2.begin(), m2.end(), hello);
		}
		if (m3.size() > 3) {
			if (c > m3[3].first) {
				m3.pop_back();
				m3.push_back({ c, x });
				sort(m3.begin(), m3.end(), hello);
			}
			else if (c == m3[3].first && x < m3[3].second) {
				m3.pop_back();
				m3.push_back({ c, x });
				sort(m3.begin(), m3.end(), hello);
			}
		}
		else {
			m3.push_back({ c, x });
			sort(m3.begin(), m3.end(), hello);
		}
		if (m4.size() > 3) {
			if (d > m4[3].first) {
				m4.pop_back();
				m4.push_back({ d, x });
				sort(m4.begin(), m4.end(), hello);
			}
			else if (d == m4[3].first && x < m4[3].second) {
				m4.pop_back();
				m4.push_back({ d, x });
				sort(m4.begin(), m4.end(), hello);
			}
		}
		else {
			m4.push_back({ d, x });
			sort(m4.begin(), m4.end(), hello);
		}
	}
	for (auto m : m1) {
		if (check(0, m)) break;
	}
	for (auto m : m2) {
		if (check(1, m)) break;
	}
	for (auto m : m3) {
		if (check(2, m)) break;
	}
	for (auto m : m4) {
		if (check(3, m)) break;
	}
}