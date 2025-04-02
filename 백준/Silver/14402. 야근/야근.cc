#include<iostream>
#include<unordered_map>
using namespace std;
int n, cnt;
string s;
char c;
unordered_map<string, int> ma;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> s >> c;
		if (c == '+') ma[s]++;
		else {
			if (ma[s]) ma[s]--;
			else cnt++;
		}
	}
	for (auto a : ma) {
		if (a.second) cnt += a.second;
	}
	cout << cnt << "\n";
	return 0;
}