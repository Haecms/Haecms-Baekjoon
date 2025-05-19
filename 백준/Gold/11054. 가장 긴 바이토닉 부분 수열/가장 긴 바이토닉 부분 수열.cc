#include<iostream>
#include<algorithm>
using namespace std;
int n, a[1004], dp1[1004], dp2[1004], ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	for (int i = 0; i < n; i++) {
		dp1[i] = 1;
		for (int j = 0; j < i; j++) {
			if (a[i] > a[j]) dp1[i] = max(dp1[i], dp1[j] + 1);
		}
	}
	for (int i = n - 1; i >= 0; i--) {
		dp2[i] = 1;
		for (int j = n - 1; j > i; j--) {
			if (a[i] > a[j]) dp2[i] = max(dp2[i], dp2[j] + 1);
		}
	}
	for (int i = 0; i < n; i++) {
		if (ret < dp1[i] + dp2[i] - 1) ret = dp1[i] + dp2[i] - 1;
	}
	cout << ret << "\n";
	return 0;
}