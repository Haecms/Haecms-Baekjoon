#include<iostream>
using namespace std;
int main() {
	int n, cnt=0;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int a = i;
		while (!(a % 5)) {
			a /= 5;
			cnt++;
		}
	}
	cout << cnt << "\n";
	return 0;
}