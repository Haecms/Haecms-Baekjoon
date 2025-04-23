#include<iostream>
#include<string>
using namespace std;
string a, b, c;

string hello(int ret) {
	if (!(ret % 3) && !(ret % 5)) return "FizzBuzz";
	if (!(ret % 3)) return "Fizz";
	if (!(ret % 5)) return "Buzz";
	return to_string(ret);
}

int main() {
	cin >> a >> b >> c;
	if (a[0] == 'F' || a[0] == 'B') {
		if (b[0] == 'F' || b[0] == 'B') cout << hello(stoi(c) + 1) << "\n";
		else cout << hello(stoi(b) + 2) << "\n";
	}
	else if (b[0] == 'F' || b[0] == 'B') cout << hello(stoi(a) + 3) << "\n";
	else if (c[0] == 'F' || c[0] == 'B') cout << hello(stoi(b) + 2) << "\n";
	else cout << hello(stoi(c) + 1) << "\n";
	return 0;
}