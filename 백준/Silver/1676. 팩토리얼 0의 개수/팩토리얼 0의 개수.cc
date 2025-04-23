#include<iostream>
using namespace std;
int n, ret;
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		int temp = i;
		while (temp >= 5 && !(temp % 5)) {
			ret++;
			temp /= 5;
		}
	}
	cout << ret << "\n";
	return 0;
}