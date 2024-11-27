#include<iostream>
using namespace std;
int n, realCnt = 0;
int main() {
	cin >> n;
	while (n >= 0) {
		if (n % 5 == 0) {
			cout << realCnt + n/5 << "\n";
			return 0;
		}
		n -= 3;
		realCnt++;
	}
	cout << -1 << "\n";
	return 0;
}