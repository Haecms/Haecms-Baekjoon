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
		if (go_up >= 0 && go_up <= 200001 && (!visited[go_up] || visited[go_up] > visited[subinPlace] + 1)) {
			visited[go_up] = visited[subinPlace] + 1;
			prevv[go_up] = subinPlace;
			q.push(go_up);
		}
		if (go_down >= 0 && go_down <= 200001 && (!visited[go_down] || visited[go_down] > visited[subinPlace] + 1)) {
			visited[go_down] = visited[subinPlace] + 1;
			prevv[go_down] = subinPlace;
			q.push(go_down);
		}
		if (go_telepote >= 0 && go_telepote <= 200001 && (!visited[go_telepote] || visited[go_telepote] > visited[subinPlace] + 1)) {
			visited[go_telepote] = visited[subinPlace] + 1;
			prevv[go_telepote] = subinPlace;
			q.push(go_telepote);
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