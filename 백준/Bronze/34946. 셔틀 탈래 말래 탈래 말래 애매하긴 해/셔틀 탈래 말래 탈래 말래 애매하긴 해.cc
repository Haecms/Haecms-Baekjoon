#include<iostream>

using namespace std;

int a, b, c, d;

int main() {
	cin >> a >> b >> c >> d;

	if (a + b <= d && c <= d) cout << "~.~";
	else if (a + b <= d) cout << "Shuttle";
	else if (c <= d) cout << "Walk";
	else cout << "T.T";

	return 0;
}