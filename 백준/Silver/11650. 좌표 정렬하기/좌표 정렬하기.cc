#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool cmp(pair<int, int> a, pair<int,int> b) {
	if (a.first == b.first) return a.second < b.second;
	return a.first < b.first;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, x, y;
	vector<pair<int, int>> v;
	cin >> n;
	while (n--) {
		cin >> x >> y;
		v.push_back({ x,y });
	}
	sort(v.begin(), v.end(), cmp);
	for (auto a : v) {
		cout << a.first << " " << a.second << "\n";
	}
	return 0;
}