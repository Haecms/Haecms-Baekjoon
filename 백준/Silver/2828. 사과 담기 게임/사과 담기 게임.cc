#include<bits/stdc++.h>
using namespace std;
int n, m, k, cp, fp, ret = 0;
int main(){
	cin >> n >> m >> k;
	cp = 1;
	for (int i = 0; i < k; i++) {
		cin >> fp;
		if (fp >= cp && fp <= cp + m - 1) continue;
		if (fp < cp) {
			ret += cp - fp;
			cp = fp;
		}
		else {
			ret += fp - cp - m + 1;
			cp = fp - m + 1;
		}
	}
	cout << ret << "\n";
}