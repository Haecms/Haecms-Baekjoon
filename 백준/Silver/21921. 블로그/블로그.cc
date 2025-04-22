#include<iostream>
using namespace std;
int n, m, a[250004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	int i = 1;
	int curV = 0;
	for (i; i <= m; i++) {
		curV += a[i];
	}
	i = m;
	int maxV = curV;
	int maxC = 1;
	while (++i <= n) {
		curV += a[i] - a[i - m];
		if (curV == maxV) maxC++;
		else if(curV > maxV) {
			maxV = curV;
			maxC = 1;
		}
	}
	if (maxV == 0) cout << "SAD" << "\n";
	else {
		cout << maxV << "\n";
		cout << maxC << "\n";
	}
	return 0;
}