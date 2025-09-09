#include<iostream>
#include<string>
using namespace std;
int n;
char c[70][70];
string go(int y, int x, int nSize) {
	char cur = c[y][x];
	if (nSize == 1) return to_string(cur-'0');
	for (int i = y; i < y + nSize; i++) {
		for (int j = x; j < x + nSize; j++) {
			if (cur != c[i][j]) {
				int hSize = nSize / 2;
				string ret = "(";
				ret += go(y, x, hSize);
				ret += go(y, x + hSize, hSize);
				ret += go(y + hSize, x , hSize);
				ret += go(y + hSize, x + hSize, hSize);
				ret += ")";
				return ret;
			}
		}
	}
	return to_string(cur-'0');
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) cin >> c[i][j];
	}
	cout << go(0, 0, n) << "\n";
	return 0;
}