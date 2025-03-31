#include<iostream>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, k, a[10004], temp;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> k;
	fill(a, a + 10004, 100000000);
	a[0] = 0;
	for (int i = 0; i < n; i++) {
		cin >> temp;
		for (int j = temp; j <= k; j++) {
			a[j] = min(a[j], a[j - temp] + 1);
		}
	}
	if (a[k] > 1000000) cout << -1 << "\n";
	else cout << a[k] << "\n";
	return 0;
}