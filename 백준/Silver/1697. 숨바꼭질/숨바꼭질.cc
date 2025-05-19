#include<iostream>
#include<queue>
using namespace std;
int n, m, visited[100004];
queue<int> q;
int main() {
	cin >> n >> m;
	q.push(n);
	visited[n] = 1;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (cur == m) {
			cout << visited[cur]-1 << "\n";
			break;
		}
		for (int a : {cur + 1, cur - 1, cur * 2}) {
			if (a < 0 || a > 100000 || visited[a]) continue;
			visited[a] = visited[cur]+1;
			q.push(a);
		}
	}
	return 0;
}