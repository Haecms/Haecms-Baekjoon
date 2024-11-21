#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n, m, p1, p2, dis, ret, visited[1001];
map<int, vector<pair<int,int>>> connect;

void go(int start, int to, int value) {
	if (start == to) {
		ret = min(value, ret);
		return;
	}
	for (int i = 0; i < connect[start].size(); i++) {
		if (visited[connect[start][i].first]) continue;
		visited[connect[start][i].first] = 1;
		value += connect[start][i].second;
		go(connect[start][i].first, to, value);
		value -= connect[start][i].second;
		visited[connect[start][i].first] = 0;
	}
}

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
		ret = 987654321;
		go(p1, p2, 0);
		cout << ret << "\n";
	}
}