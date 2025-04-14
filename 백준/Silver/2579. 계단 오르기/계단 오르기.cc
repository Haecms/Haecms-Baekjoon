#include<iostream>
#include<queue>
using namespace std;
int n, a[304], ret, visited[304][2];
struct A { int idx, nValue, cnt; };
queue<A> q;
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		visited[i][0] = -1;
		visited[i][1] = -1;
	}
	visited[0][0] = -1;
	q.push({ 0,0,0 });
	while (q.size()) {
		int idx = q.front().idx;
		int value = q.front().nValue;
		int cnt = q.front().cnt;
 		q.pop();
		if (idx == n) {
			ret = max(ret, value);
			continue;
		}
		if (visited[idx][cnt] >= value) continue;
		if (idx == n - 1 && cnt == 2) continue;
		visited[idx][cnt] = value;
		if(cnt != 2 && idx+1 <= n) q.push({ idx + 1, a[idx + 1] + value, cnt+1 });
		if(idx + 2 <= n)q.push({ idx + 2, a[idx + 2] + value, 1 });
	}
	cout << ret << "\n";
	return 0;
}