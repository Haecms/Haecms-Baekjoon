#include<iostream>
using namespace std;
int n, m, a[100004],b, cnt;
int main() {
	cin >> n >> m;
	while (n--) {
		cin >> b;
		a[b]++;
	}
	for (int i = 1; i < 100001; i++) {
		if (a[i] && m-i > 0 && m-i < 100001 && a[m-i] && i != m-i) {
			cnt++;
			a[i]--; a[m-i]--;
		}
	}
	cout << cnt << "\n";
	return 0;
}