#include<iostream>
#include<algorithm>
#include<math.h>
using namespace std;
int n, a[100004], minSum = 2000000001;
pair<int, int> ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	sort(a, a + n);
	int li = 0, ri = n-1;
	while (li < ri) {
		int curV = a[li] + a[ri];
		if (abs(curV) < minSum) {
			minSum = abs(curV);
			ret.first = a[li];
			ret.second = a[ri];
		}
		if (curV > 0) ri--;
		else if (!curV) break;
		else li++;
	}
	cout << ret.first << " " << ret.second << "\n";
	return 0;
}