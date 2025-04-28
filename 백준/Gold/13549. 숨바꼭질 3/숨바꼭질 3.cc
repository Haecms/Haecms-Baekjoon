#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;

int n, m, dp[200004];
queue<pair<int, int>> q;

int main() {
	fill(dp, dp + 200004, 1000000);
	cin >> n >> m;
	q.push({ n,0 });
	
	while (q.size()) {
		int cur = q.front().first;
		int ttime = q.front().second;
		q.pop();
		if (dp[cur] != 1000000 && dp[cur] < ttime) continue;
		dp[cur] = ttime;
		if (cur == m) {
			cout << ttime << "\n";
			break;
		}
		if (cur - 1 >= 0 && dp[cur - 1] > ttime + 1) {
			q.push({ cur - 1, ttime + 1 });
			dp[cur - 1] = min(dp[cur-1], ttime + 1);
		}
		if (cur + 1 <= 100000 && dp[cur + 1] > ttime + 1) {
			q.push({ cur + 1, ttime + 1 });
			dp[cur + 1] = min(dp[cur + 1], ttime + 1);
		}
		if (cur * 2 <= 200000 && dp[cur * 2] > ttime) {
			q.push({ cur * 2, ttime });
			dp[cur * 2] = min(dp[cur * 2], ttime);
		}
	}
	return 0;
}