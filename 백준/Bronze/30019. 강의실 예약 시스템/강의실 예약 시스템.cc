#include<iostream>
using namespace std;
int n, m, k, s, e, arr[200001];

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> k >> s >> e;
		if (arr[k]) {
			if (arr[k] <= s) {
				arr[k] = e;
				cout << "YES" << "\n";
			}
			else cout << "NO" << "\n";
		}
		else {
			arr[k] = e;
			cout << "YES" << "\n";
		}
	}
}
