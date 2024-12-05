#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;
unordered_map<int, vector<int>> ma;
int n, m, visited[1001], u, x, cnt=0;
void check(int num) {
	visited[num] = 1;
	for (int a : ma[num]) {
		if (visited[a]) continue;
		check(a);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	while (m--) {
		cin >> u >> x;
		ma[u].push_back(x);
		ma[x].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			cnt++;
			check(i);
		}
	}
	cout << cnt << "\n";
	return 0;
}