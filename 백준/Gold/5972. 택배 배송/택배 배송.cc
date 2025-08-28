#include<iostream>
#include<vector>
#include<queue>
using namespace std;
int n, m,a,b,c, visited[50004];
vector<pair<int, int>> v[50004];
struct A {
	int cur, nDis;
	bool operator<(const A& a) const {
		return nDis > a.nDis;
	}
};
priority_queue<A> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		v[b].push_back({ a,c });
	}
	q.push({ 1, 0 });
	while (q.size()) {
		int cur = q.top().cur;
		int nDis = q.top().nDis;
		q.pop();
		if (visited[cur]) continue;
		if (cur == n) {
			cout << nDis << "\n";
			break;
		}
		visited[cur] = 1;
		for (auto vv : v[cur]) {
			if (visited[vv.first]) continue;
			q.push({ vv.first, nDis + vv.second });
		}
	}
	return 0;
}