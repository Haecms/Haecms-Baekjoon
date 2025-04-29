#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int n, m, a[51][51];
vector<pair<int, int>> home;
vector<pair<int,int>> v1;
vector<vector<pair<int,int>>> v_chicken;

void go(int idx, vector<pair<int,int>>& v2) {
	if (v2.size() == m) v_chicken.push_back(v2);
	else {
		for (int i = idx; i < v1.size(); i++) {
			v2.push_back(v1[i]);
			go(i + 1, v2);
			v2.pop_back();
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j];
			if (a[i][j] == 2) v1.push_back({ i,j });
			else if (a[i][j]) home.push_back({ i,j });
		}
	}
	vector<pair<int, int>> v2;
	go(0, v2);
	int ret = 20000000;
	for (int i = 0; i < v_chicken.size(); i++) {
		int cnt = 0;
		for (pair<int, int> house : home) {
			int distance = 20000000;
			for (pair<int, int> chicken : v_chicken[i]) {
				distance = min(distance, abs(house.first - chicken.first) + abs(house.second - chicken.second));
			}
			cnt += distance;
		}
		ret = min(cnt, ret);
	}
	cout << ret << "\n";
	return 0;
}