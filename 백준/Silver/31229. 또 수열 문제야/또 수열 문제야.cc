#include<iostream>
using namespace std;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	long long n, a=-1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		a += 2;
		cout << a << " ";
	}
	return 0;
}