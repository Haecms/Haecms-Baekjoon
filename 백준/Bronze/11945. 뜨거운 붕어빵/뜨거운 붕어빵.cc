#include<iostream>
using namespace std;
int n, m, a[14][14];
char c;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			a[i][j] = c - '0';
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = m-1; j >= 0; j--) {
			cout << a[i][j];
		}
		cout << "\n";
	}
	return 0;
}