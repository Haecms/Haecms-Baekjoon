#include<iostream>
#include<queue>
using namespace std;
int s, b, visited[100004], trace[100004];
queue<int>q;

void goTrace(int cur) {
	if (trace[cur] != cur) goTrace(trace[cur]);
	cout << cur << " ";
}
int main() {
	cin >> s >> b;
	for (int i = 0; i < 100001; i++) visited[i] = 100000000;
	q.push(s);
	visited[s] = 0;
	trace[s] = s;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (cur == b) break;

		for (int nxt : {cur + 1, cur - 1, cur * 2}) {
			if (nxt >= 0 && nxt <100001 && visited[nxt] > visited[cur] + 1) {
				visited[nxt] = visited[cur] + 1;
				trace[nxt] = cur;
				q.push(nxt);
			}
		}
	}
	cout << visited[b] << "\n";
	goTrace(b);
	return 0;
}