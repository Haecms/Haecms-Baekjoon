#include<iostream>
#include<queue>
using namespace std;
int n, m, maxCnt = 1e9, ret, visited[200004];
queue<pair<int, int>> q;
int main() {
	for (int i = 0; i < 200004; i++) visited[i] = 1e9;
	cin >> n >> m;
	q.push({ n,1 });
	visited[n] = 1;
	while (q.size()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (maxCnt < cnt) break;
		if (cur == m) {
			maxCnt = cnt;
			ret++;
			continue;
		}
		int next_pos[3] = {cur - 1, cur + 1, cur * 2};
		for (int nxt : next_pos) {
			if (nxt >= 0 && nxt <= 200000 && visited[nxt] >= cnt + 1) {
				visited[nxt] = cnt + 1;
				q.push({ nxt, cnt + 1 });
			}
		}
	}
	cout << maxCnt-1 << "\n" << ret << "\n";
	return 0;
}