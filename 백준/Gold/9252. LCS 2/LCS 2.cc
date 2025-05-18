#include<iostream>
#include<algorithm>
using namespace std;
string s1, s2;
int a[1004][1004];
int main() {
	cin >> s1 >> s2;
	s1 = " " + s1;
	s2 = " " + s2;
	for (int i = 1; i < s1.size(); i++) {
		for (int j = 1; j < s2.size(); j++) {
			if (s1[i] == s2[j]) a[i][j] = a[i - 1][j - 1]+1;
			else a[i][j] = max(a[i - 1][j], a[i][j - 1]);
		}
	}
	cout << a[s1.size() - 1][s2.size() - 1] << "\n";
	int y = s1.size() - 1;
	int x = s2.size() - 1;
	int curValue = a[y][x];
	string ret = "";
	while (a[y][x] != 0) {
		if (a[y - 1][x] == curValue) y--;
		else if (a[y][x - 1] == curValue) x--;
		else {
			ret = s1[y] + ret;
			curValue--;
			y--;
			x--;
		}
	}
	cout << ret << "\n";
	return 0;
}