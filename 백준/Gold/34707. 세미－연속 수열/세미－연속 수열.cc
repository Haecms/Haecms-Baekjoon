#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>

using namespace std;
typedef long long ll;
int n, k, a[500004], idx;
ll b[500004];
bool flag = false;

unordered_map<ll, int> um;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		b[i] = a[i] + b[i - 1];
	}
	ll curV = 0;
	for (int i = 1; i <= k; i++) {
		curV += i;
	}
	um[curV]++;
	for (int i = k + 1; i <= n; i++) {
		curV -= i - k;
		curV += i;
		um[curV]++;
	}
	for(int i=k; i<= n; i++){
		ll sum = b[i] - b[i - k];
		if (um[sum]) {
			vector<ll> v;
			for (int j = i - k + 1; j <= i; j++) { v.push_back(a[j]); }
			sort(v.begin(), v.end());
			if (v[0] + k - 1 == v[v.size() - 1]) {
				flag = true;
				idx = i - k + 1;
				break;
			}
		}
	}
	if (flag) {
		cout << "YES\n";
		for (int i = idx; i < idx + k; i++) {
			cout << a[i] << " ";
		}
	}
	else cout << "NO\n";

	return 0;
}