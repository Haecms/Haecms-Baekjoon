#include<iostream>
using namespace std;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int a,b;
	while (true) {
		cin >> a >> b;
		if (a == cin.eof() || b == cin.eof()) break;
		cout << a + b << "\n";
	}
}