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