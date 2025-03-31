#include<iostream>
using namespace std;
int n, k, a[10004], temp, cnt;
int main() {
	cin >> n >> k;
	a[0] = 1;
	while (n--) {
		cin >> temp;
		if (temp >= 10001) continue;
		for (int i = temp; i <= k; i++) a[i] += a[i-temp];
	}
	cout << a[k] << "\n";
	return 0;
	
}