#include<iostream>
#include<unordered_map>
#include<string>
using namespace std;
unordered_map<string, int> um;
string ss[100004];
int n, m;
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> s;
		um[s] = i;
		ss[i] = s;
	}
	while (m--) {
		cin >> s;
		if (atoi(s.c_str())) cout << ss[atoi(s.c_str())] << "\n";
		else cout << um[s] << "\n";
	}
	return 0;
}