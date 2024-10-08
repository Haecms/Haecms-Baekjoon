#include<iostream>
using namespace std;
int n, a[5001], before_a = 0, max_cnt = 0;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	bool plus = false;
	bool minus = false;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		if (before_a > 0) {
			if (before_a < a[i]) {
				plus = true;
				if (minus) {
					plus = false;
					minus = false;
					max_cnt = max(max_cnt, cnt);
					cnt = 0;
					i -= 2;
					continue;
				}
			}
			else if (before_a > a[i]) {
				minus = true;
			}
			else if (before_a == a[i]) {
				plus = false;
				minus = false;
				max_cnt = max(max_cnt, cnt);
				cnt = 0;
			}
		}
		before_a = a[i];
		cnt++;
		if (i == n - 1) {
			max_cnt = max(max_cnt, cnt);
		}
	}
	cout << max_cnt << "\n";
}