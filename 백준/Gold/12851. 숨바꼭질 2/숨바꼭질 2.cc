#include<iostream>
#include<queue>
using namespace std;
int s, b, visited[100004], ret = 1000000, cnt;
queue<int>q;
int main() {
	for (int i = 0; i < 100001; i++) visited[i] = 1000000;
	cin >> s >> b;
	q.push(s);
	visited[s] = 1;
	while (q.size()) {
		int cur = q.front();
		q.pop();
		if (ret < visited[cur]) break;
		if (cur == b) {
			ret = visited[cur];
			cnt++;
			continue;
		}
		for (int nxt : {cur - 1, cur + 1, cur * 2}) {
			if (nxt >= 0 && nxt < 100001 && visited[nxt] >= visited[cur] + 1) {
				q.push(nxt);
				visited[nxt] = visited[cur] + 1;
			}
		}
	}
	cout <<	ret -1 << "\n" << cnt << "\n";
	return 0;
}