#include<iostream>
using namespace std;
long long n, m, a[1004], sum, v, ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> v;
		sum += v;
		a[sum % m]++;
	}
	for (int i = 0; i <= m; i++) {
		ret += a[i] * (a[i] - 1) / 2;
	}
	cout << a[0] + ret << "\n";
}
