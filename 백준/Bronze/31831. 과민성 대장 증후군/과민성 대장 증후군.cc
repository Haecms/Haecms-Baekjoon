#include<iostream>
using namespace std;
int n, m, a, ret=0, cnt=0;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		ret += a;
		if (ret < 0) ret = 0;
		if (ret >= m) cnt++;
	}
	cout << cnt << "\n";
}
