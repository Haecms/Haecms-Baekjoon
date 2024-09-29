#include<iostream>
using namespace std;
int n;
int main() {
	cin >> n;
	if (n < 3) cout << 1 << "\n";
	else if (n < 6) cout << 2 << "\n";
	else cout << 3 << "\n";
}