#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
long long n, a[10004], ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	int li = 0, ri = n-1;
	if (n % 2 == 1) ret = a[n - 1], ri=n-2;
	while (li <= ri) {
		long long sum = a[li++] + a[ri--];
		ret = max(ret, sum);
	}
	cout << ret << "\n";
	return 0;
}