#include<iostream>
using namespace std;
int n,m;
int main() {
	cin >> n;
	for (;n;n >>= 1) m += n & 1;
	cout << m << "\n";
	return 0;
}