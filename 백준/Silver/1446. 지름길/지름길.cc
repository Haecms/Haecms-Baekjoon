#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n, m, visited[10004], a,b,c;
vector<pair<int, int>> v[10004];
struct A {
	int cur, sum;
	bool operator<(const A& a) const {
		return sum > a.sum;
	}
};
priority_queue<A> pq;
bool cmp(pair<int,int> a, pair<int,int> b) {
	return a.second < b.second;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
	}
	for (int i = 0; i <= n; i++) {
		sort(v[i].begin(), v[i].end(), cmp);
	}
	pq.push({ 0,0 });
	while (pq.size()) {
		int cur = pq.top().cur;
		int sum = pq.top().sum;
		pq.pop();
		if (cur > m) continue;
		if (cur == m) break;
		if (v[cur].size()) {
			for (int i = 0; i < v[cur].size(); i++) {
				if (!visited[v[cur][i].first] || visited[v[cur][i].first] > sum + v[cur][i].second) {
					pq.push({ v[cur][i].first, sum + v[cur][i].second });
					visited[v[cur][i].first] = sum + v[cur][i].second;
				}
			}
		}
		if (visited[cur + 1] && visited[cur + 1] <= sum + 1) continue;
		pq.push({ cur + 1, sum + 1 });
		visited[cur + 1] = sum + 1;
	}
	cout << visited[m] << "\n";
	return 0;
}