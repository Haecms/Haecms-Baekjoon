#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a, ret;
vector<int> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end(), greater<>());
	while (v.size()) {
		ret++;
		int range = v[v.size() - 1];
		for (int i = 0; i < range; i++) { 
			v.pop_back(); 
			if (!v.size()) break;
		}
	}
	cout << ret << "\n";
	return 0;
}