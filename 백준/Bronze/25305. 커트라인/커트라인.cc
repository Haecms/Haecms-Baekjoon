#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[1004];
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	cout << a[n-m] << "\n";
	return 0;
}