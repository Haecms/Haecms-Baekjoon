#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, m, city[1004], a,b,c, realFrom, realTo;
vector<pair<int, int>> v[100004];
struct A { 
	int cost, from;
	bool operator < (const A& d) const {
		return cost > d.cost;
	}
};
priority_queue<A> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		cin >> a >> b >> c;
		v[a].push_back({ b,c });
		//v[b].push_back({ a,c });
	}
	cin >> realFrom >> realTo;
	pq.push({ 0, realFrom });
	
	while (pq.size()) {
		int curFrom = pq.top().from;
		int curCost = pq.top().cost;
		pq.pop();
		if (curFrom == realTo) {
			cout << curCost << "\n";
			break;
		}
		if (city[curFrom]) continue;
		city[curFrom] = 1;
		for (auto vv : v[curFrom]) {
			if (city[vv.first]) continue;
			pq.push({ curCost + vv.second, vv.first });
		}
	}
	return 0;
}