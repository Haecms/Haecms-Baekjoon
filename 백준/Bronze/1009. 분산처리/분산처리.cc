#include<iostream>
using namespace std;
int a, b, c;
int main() {
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> b >> c;
		int d = 1;
		for (int j = 0; j < c; j++) {
			d = (d*b) % 10;
			if (d == 0) d = 10;
		}
		cout << d << "\n";
	}
	return 0;
}