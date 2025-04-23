#include<iostream>
#include<math.h>
using namespace std;
int n, a[100004], diff = 2000000001, bV, sV;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	int li = 0, ri = n - 1;
	while (li < ri) {
		int curdiff = abs(a[li] + a[ri]);
		if (curdiff < diff) {
			diff = curdiff;
			sV = a[li];
			bV = a[ri];
		}
		if (abs(a[li + 1] + a[ri]) <= abs(a[li] + a[ri - 1])) {
			li++;
		}
		else ri--;
	}
	cout << sV << " " << bV << "\n";
	return 0;
}