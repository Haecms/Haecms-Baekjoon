#include<iostream>
#include<algorithm>
using namespace std;
int n, m, a[104], ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			for (int k = j + 1; k < n; k++) {
				if(a[i]+a[j]+a[k] <= m) ret = max(a[i] + a[j] + a[k], ret);
			}
		}
	}
	cout << ret << "\n";
	return 0;
}