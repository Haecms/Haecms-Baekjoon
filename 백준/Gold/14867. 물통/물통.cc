#include<iostream>
#include<map>
#include<queue>
#include<algorithm>
using namespace std;
int a, b, c, d;
struct A { int y, x, cnt; };
map<pair<int, int>, int> visited;
queue<A> q;
int go() {
	q.push({ 0,00 });
	while (q.size()) {
		int curY = q.front().y;
		int curX = q.front().x;
		int curCnt = q.front().cnt;
		if (curY == c && curX == d) return curCnt;
		q.pop();
		if (visited[{curY, curX}]) continue;
		visited[{curY, curX}] = 1;
		q.push({ a, curX, curCnt + 1 });
		q.push({ curY, b, curCnt + 1 });
		q.push({ 0, curX, curCnt + 1 });
		q.push({ curY, 0, curCnt + 1 });
		q.push({ min(curY + curX, a), max(curX + curY - a, 0), curCnt + 1});
		q.push({ max(curX+curY - b, 0), min(curY + curX, b), curCnt + 1});
	}
	return -1;
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> a >> b >> c >> d;
	cout << go() << "\n";
	return 0;
}