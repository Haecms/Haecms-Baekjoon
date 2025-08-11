#include<iostream>
#include<queue>
using namespace std;
int n,m,a[6][6],ret = 1000000000;
int dx[3] = { -1,0,1 };
struct A {
	int y, x, sum, pre;
};
queue<A> q;
int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) cin >> a[i][j];
	}
	for (int i = 0; i < m; i++) q.push({ 0, i, a[0][i], 4 });
	while (q.size()) {
		int y = q.front().y;
		int x = q.front().x;
		int sum = q.front().sum;
		int pre = q.front().pre;
		q.pop();
		if (y == n-1) {
			ret = min(ret, sum);
			continue;
		}
		for (int i = 0; i < 3; i++) {
			if (i == pre) continue;
            int nx = x + dx[i];
			if(nx >=0 && nx < m) q.push({ y + 1, nx, sum + a[y + 1][nx], i });
		}
	}
	cout << ret << "\n";
	return 0;
}