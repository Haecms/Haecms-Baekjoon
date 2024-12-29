#include<iostream>
using namespace std;
int n, m, arr[100004], a;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a;
		arr[i] = a + arr[i - 1];
	}
	while (m--) {
		cin >> n >> a;
		cout << arr[a] - arr[n - 1] << "\n";
	}
}