#include<iostream>
#include<memory.h>
using namespace std;
int a, b, c, e[12];

int main() {
	cin >> a;
	while (a--) {
		cin >> b >> c;
		int d = b % 10 != 0 ? b % 10 : 10;
		e[1] = d;
		int index = 0;
		for (int j = 2; j <= c + 1; j++) {
			d = d * b % 10 != 0 ? d * b % 10 : 10;
			if (e[1] == d) { index = j - 1; break; }
			else { e[j] = d; }
			index = j - 1;
		}
		if (c % index == 0) cout << e[index] << "\n";
		else cout << e[c % index] << "\n";

		memset(e, 0, sizeof(e));
	}
	return 0;
}