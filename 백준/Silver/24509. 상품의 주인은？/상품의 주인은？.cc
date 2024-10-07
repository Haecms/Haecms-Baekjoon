#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, x, a, b, c, d;
vector<pair<int, int>> m1, m2, m3, m4;
string s = "0000";
bool hello(pair<int, int> a, pair<int, int> b) {
	if (a.first == b.first) {
		return a.second < b.second;
	}
	return a.first > b.first;
}
void pushGrade(vector<pair<int, int>>& v, int score, int grade) {
	if (v.size() > 3) {
		if (score > v[3].first || (score == v[3].first && grade < v[3].second)) {
			v.pop_back();
			v.push_back({ score, grade });
			sort(v.begin(), v.end(), hello);
		}
	}
	else {
		v.push_back({ score, grade });
		sort(v.begin(), v.end(), hello);
	}
}
bool check(int index, pair<int, int> e) {
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
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> x >> a >> b >> c >> d;
		pushGrade(m1, a, x);
		pushGrade(m2, b, x);
		pushGrade(m3, c, x);
		pushGrade(m4, d, x);
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