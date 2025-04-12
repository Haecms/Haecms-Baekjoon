#include<iostream>
#include<queue>
#include<memory.h>
using namespace std;
int n, a[130][130],cnt, visited[130][130];
const int dy[4] = { 0,1,0,-1 };
const int dx[4] = { 1,0,-1,0 };
struct A {
	int y;
	int x;
	int nValue;

	bool operator<(const A &b) const {
		return nValue > b.nValue;
	}
};
priority_queue<A> pq;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	while (1) {
		cin >> n;
		if (!n) break;
		cnt++;
		pq = priority_queue<A>();
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		fill(&visited[0][0], &visited[0][0] + 130 * 130, 0);
		pq.push({ 0,0,a[0][0] });
		while (pq.size()) {
			int curY = pq.top().y;
			int curX = pq.top().x;
			int value = pq.top().nValue;
			if (curY == n - 1 && curX == n - 1) {
				cout << "Problem " << cnt << ": " << value << "\n";
				break;
			}
			pq.pop();
			visited[curY][curX] = 1;
			for (int i = 0; i < 4; i++) {
				int ny = dy[i] + curY;
				int nx = dx[i] + curX;
				if (ny < 0 || nx < 0 || ny >= n || nx >= n || visited[ny][nx]) continue;
				pq.push({ ny,nx,value + a[ny][nx] });
			}
		}
	}
	return 0;
}
