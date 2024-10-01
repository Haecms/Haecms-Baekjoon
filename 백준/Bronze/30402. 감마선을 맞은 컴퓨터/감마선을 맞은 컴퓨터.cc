#include<iostream>
using namespace std;
char a;
int b = 225;
int main() {
	while (b--) {
		cin >> a;
		if (a == 'w' || a == 'b' || a == 'g') break;
	}
	if (a == 'w') cout << "chunbae";
	else if (a == 'b') cout << "nabi";
	else cout << "yeongcheol";
}