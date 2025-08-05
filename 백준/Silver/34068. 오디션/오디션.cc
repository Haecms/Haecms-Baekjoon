#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
long long n, m, a, b, ret;
vector<long long> v;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) v.push_back(0);
	for (int i = 0; i < m; i++) {
		cin >> a >> b;
		v[a-1]++;
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size()-1; i++) {
		if (v[i] >= v[i + 1]) {
			ret += v[i] - v[i + 1] + 1;
			v[i + 1] = v[i] + 1;
		}
	}
	cout << ret << "\n";
	return 0;
}