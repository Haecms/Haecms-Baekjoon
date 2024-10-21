#include<iostream>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
int subin, brother, visited[400004], minTime=2000000, prevv[400004];
queue<int> q;
vector<int> v;
int main() {
	cin >> subin >> brother;
	q.push(subin);
	visited[subin] = 1;
	while (q.size()) {
		int subinPlace = q.front();
		if (subinPlace == brother) {
			minTime = min(minTime, visited[subinPlace] - 1);
			q.pop();
			continue;
		}
		q.pop();
		int go_up = subinPlace + 1;
		int go_down = subinPlace - 1;
		int go_telepote = subinPlace * 2;
		for (int next : {go_up, go_down, go_telepote}) {
			if (next >= 0 && next <= 200001 && (!visited[next] || visited[next] > visited[subinPlace] + 1)) {
				visited[next] = visited[subinPlace] + 1;
				prevv[next] = subinPlace;
				q.push(next);
			}
		}
	}
	for (int i = brother; i != subin; i = prevv[i]) {
		v.push_back(i);
	}
	v.push_back(subin);
	reverse(v.begin(), v.end());
	cout << minTime << "\n";
	for (int i : v) cout << i << " ";
	return 0;
}