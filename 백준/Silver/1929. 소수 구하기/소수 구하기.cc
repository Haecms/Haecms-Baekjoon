#include<iostream>
using namespace std;
int n, m, prime[1000001];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	prime[1] = 1;
	for (int i = 4; i <= m; i += 2) prime[i] = 1;
	for (int i = 3; i*i <= m; i += 2) {
		if (prime[i]) continue;
		for (int j = i*i; j <= m; j += i * 2) prime[j] = 1;
	}
	for (int i = n; i <= m; i++) {
		if (!prime[i]) cout << i << "\n";
	}
	return 0;
}