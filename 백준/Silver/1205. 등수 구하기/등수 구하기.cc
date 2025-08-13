#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n, s, p, a, ret, cnt=1;
vector<int> v;
int main() {
	cin >> n >> s >> p;
	while (n--) {
		cin >> a;
		v.push_back(a);
	}
	v.push_back(s);
	sort(v.begin(), v.end(), greater<>());
	for (int b : v) {
		if (b == s) ret = cnt;
		cnt++;
	}
	if (ret > p) ret = -1;
	if (ret != -1) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] == s) { ret = i + 1; break; }
		}
	}
	cout << ret << "\n";
	return 0;
}