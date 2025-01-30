#include<iostream>
#include<vector>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0);  cin.tie(0); cout.tie(0);
	int n, a;
	string s;
	cin >> n;
	vector<string> v[201];
	while (n--) {
		cin >> a >> s;
		v[a].push_back(s);
	}
	for (int i = 1; i < 201; i++) {
		for (string s : v[i]) {
			cout << i << " " << s << "\n";
		}
	}
	return 0;
}