#include<iostream>
#include<map>
#include<vector>
#include<queue>
using namespace std;
int n, m, p1, p2, dis;
map<int, vector<pair<int,int>>> connect;

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		cin >> p1 >> p2 >> dis;
		connect[p1].push_back({ p2, dis });
		connect[p2].push_back({ p1, dis });
	}
	while (m--) {
		cin >> p1 >> p2;
		queue<pair<int,int>> q;
		int visited[1001] = {};
		q.push({ p1, 0 });
		visited[p1] = 1;
		while (q.size()) {
			int start = q.front().first;
			int dis = q.front().second;
			q.pop();
			if (start == p2) {
				cout << dis << "\n";
				break;
			}
			for (int i = 0; i < connect[start].size(); i++) {
				if (visited[connect[start][i].first]) continue;
				visited[connect[start][i].first] = 1;
				q.push({ connect[start][i].first,  dis + connect[start][i].second });
			}
		}
	}
}