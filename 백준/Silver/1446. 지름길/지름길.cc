#include<iostream>
#include<vector>
#include<climits>
using namespace std;
int n, m, a,b,c, visited[10004];
vector<pair<int, int>> v[10004];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) visited[i] = INT_MAX;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		if (b > m) continue;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i <= m; i++) {
		if (i) visited[i] = min(visited[i], visited[i - 1] + 1);
		if (v[i].size()) {
			for (auto d : v[i]) {
				visited[d.first] = min(visited[d.first], visited[i] + d.second);
			}
		}
	}
	cout << visited[m] << "\n";
	return 0;
}