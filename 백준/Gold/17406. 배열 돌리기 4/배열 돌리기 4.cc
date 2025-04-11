#include<iostream>
#include<vector>
#include<algorithm>
#include<memory.h>
using namespace std;
int n, m, k, a[52][52], y,x,cnt, visited[6], ret=1000000000;
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
struct A {
	int y;
	int x;
	int cnt;
};
vector<A> v;
void go(int count, int arr[][52]);

void go2(int col, int row, int s, int arr[][52], int count) {
	int temp[52][52];
	memcpy(temp, arr, sizeof(temp));
		int idx_y = col-s-1;
		int idx_x = row-s-1;
		int end_idx_y = col + s;
		int end_idx_x = row + s;
		int ny = idx_y;
		int nx = idx_x;
		while (idx_y < end_idx_y && idx_x < end_idx_x) {
			for (int i = 0; i < 4; i++) {
				while (true) {
					ny += dy[i];
					nx += dx[i];
					if (ny >= end_idx_y || nx >= end_idx_x || ny < idx_y || nx < idx_x) {
						ny -= dy[i];
						nx -= dx[i];
						break;
					}
					temp[ny][nx] = arr[ny - dy[i]][nx - dx[i]];
				}
			}
			idx_y++;
			idx_x++;
			end_idx_y--;
			end_idx_x--;
			ny++;
			nx++;
		}
	go(count + 1, temp);
}

void go(int count, int arr[][52]) {
	if (count == v.size()) {
		for (int i = 0; i < n; i++) {
			int sum = 0;
			for (int j = 0; j < m; j++) {
				sum += arr[i][j];
			}
			ret = min(ret, sum);
		}
		return;
	}

	for (int i = 0; i < v.size(); i++) {
		if (visited[i]) continue;
		visited[i] = 1;
		go2(v[i].y, v[i].x, v[i].cnt, arr, count);
		visited[i] = 0;
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < k; i++) {
		cin >> y >> x >> cnt;
		v.push_back({ y,x,cnt });
	}
	go(0, a);
	cout << ret << "\n";
	return 0;
}

