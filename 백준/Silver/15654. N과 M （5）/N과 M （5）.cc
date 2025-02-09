#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, a, visited[10004];
vector<int> v;
string s = "";
void go(string s, int cnt) {
	if (cnt == m) cout << s.substr(0, s.size()-1) << "\n";
	else {
		for (int i : v) {
			if (visited[i]) continue;
			visited[i] = 1;
			string ss = s;
			s += (to_string(i) + ' ');
			go(s, cnt + 1);
			visited[i] = 0;
			s = ss;
		}
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	go(s, 0);
	return 0;
}