#include<iostream>
using namespace std;
int a, b;
int main() {
	cin >> a >> b;
	cout << fixed;
	cout.precision(10);
	cout << a/ (double)b;
	return 0;
}