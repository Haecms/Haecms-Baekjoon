#include<iostream>
#include<math.h>
#include<memory.h>
using namespace std;
int n;
char c[1000004];
void go(int cnt, int startPoint, int endPoint, int difference) {
	if (difference == 1) {
		c[startPoint] = '-';
		c[startPoint+1] = ' ';
		c[startPoint+2] = '-';
	}
	else {
		go(cnt + 1, startPoint, startPoint + difference, difference / 3);
		go(cnt + 1, endPoint - difference, endPoint, difference / 3);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (true) {
		cin >> n;
		if (cin.eof()) break;
		if (n == 0) {
			cout << "-\n"; 
			continue;
		}
		int r = pow(3, n);
		memset(c, ' ', c[0] + r);
		go(0, 0, r, r / 3);
		for (int i = 0; i < r; i++) cout << c[i];
		cout << '\n';
	}
	
}