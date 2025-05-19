#include<iostream>
#include<queue>
using namespace std;
int n, m, visited[100004];
queue<pair<int, int>> q;
int main() {
	cin >> n >> m;
	q.push({ n,1 });
	while (q.size()) {
		int cur = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (cur == m) {
			cout << cnt-1 << "\n";
			break;
		}
		visited[cur] = 1;
		if (cur + 1 <= 100001 && !visited[cur + 1]) {
			q.push({ cur + 1, cnt + 1 });
			visited[cur + 1] = 1;
		}
		if (cur - 1 >= 0 && !visited[cur - 1]) {
			q.push({ cur - 1, cnt + 1 });
			visited[cur - 1] = 1;
		}
		if (cur * 2 <= 100001 && !visited[cur * 2]) {
			q.push({ cur * 2, cnt + 1 });
			visited[cur * 2] = 1;
		}
	}
	return 0;
}