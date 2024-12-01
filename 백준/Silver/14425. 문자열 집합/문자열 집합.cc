#include<iostream>
#include<unordered_map>
using namespace std;
int n, m, ret = 0;
string s;
unordered_map<string, int> ma;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (n--) {
		cin >> s;
		ma[s] = 1;
	}
	while (m--) {
		cin >> s;
		if (ma[s]) ret++;
	}
	cout << ret << "\n";
}