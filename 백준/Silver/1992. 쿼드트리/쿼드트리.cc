#include <bits/stdc++.h>
using namespace std;
char s, a[104][104];

string quad(int y, int x, int size) {
	if (size == 1) return string(1, a[y][x]);
	char b = a[y][x];
	string ret;
	for (int i = y; i < y + size; i++) {
		for (int j = x; j < x + size; j++) {
			if (b != a[i][j]) {
				int nsize = size / 2;
				ret += "(";
				ret += quad(y, x, nsize);
				ret += quad(y, x + nsize, nsize);
				ret += quad(y + nsize, x, nsize);
				ret += quad(y + nsize, x + nsize, nsize);
				ret += ")";
				return ret;
			}
		}
	}
	return string(1, a[y][x]);
}

int main() {
	int N;
	cin >> N;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			cin >> s;
			a[i][j] = s;
		}
	}
	cout << quad(0, 0, N) << "\n";
}