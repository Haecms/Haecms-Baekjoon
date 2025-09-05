#include<iostream>
using namespace std;
int n, m, dog[104], wash, state[104], ret, hello[104];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <=n; i++) cin >> dog[i];
	for (int i = 1; i <=m; i++) {
		cin >> wash;
		for (int j = 1; j <= n; j++) {
			if (j == wash) {
				if (state[j] >= dog[j]) {
					if (hello[j]) {
						hello[j] = 0;
						state[j] = 0;
					}
					else hello[j] = 1;
				}
				else state[j] = 0;
			}
			else {
				if (hello[j]) hello[j] = 0;
				else state[j]++;
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (state[i] >= dog[i] || hello[i]) ret++;
	}
	cout << ret << "\n";
	return 0;
}