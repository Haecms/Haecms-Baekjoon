#include<iostream>
using namespace std;
int a, b[10001], c;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a;
	for (int i = 0; i < a; i++) {
		cin >> c;
		b[c] += 1;
	}
	
	for (int i = 0; i < 10001; i++) {
		while (b[i]) {
			cout << i << '\n';
			b[i]--;
		}
	}
}