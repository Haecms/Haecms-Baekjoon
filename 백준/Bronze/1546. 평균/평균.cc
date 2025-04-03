#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
float n, m, bi, ret;
vector<float> v;
int main() {
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> m;
		v.push_back(m);
	}
	sort(v.begin(), v.end());
	for (int i = 0; i < v.size(); i++) ret += v[i] / v[v.size() - 1] * 100;
	cout << ret / n << "\n";
}