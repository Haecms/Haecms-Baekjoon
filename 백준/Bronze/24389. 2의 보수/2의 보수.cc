#include<iostream>
using namespace std;
int main() {
	int n, cnt=0;
	cin >> n;
	int m = ~n + 1;
	for (int i = 0; i < 32; i++) {
		if ((n >> i & 1) != (m >> i & 1)) cnt++;
	}
	cout << cnt;
}