#include<iostream>
using namespace std;
long long n, ret=1;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) ret *= i;
	cout << ret << "\n";
	return 0;
}