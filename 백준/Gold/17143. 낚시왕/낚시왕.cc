#include<iostream>
#include<vector>
#include<memory.h>
using namespace std;
const int dy[4] = {-1,1,0,0 };
const int dx[4] = {0,0,1,-1 };
int a[104][104], ret, n, m, k;
int shark[100004]; 
struct A { int y, x, speed, direction, size; };
vector<A> v(100004);

void Go(int col) {
	for (int i = 1; i <= n; i++) {
		if (a[i][col]) {
			ret += v[a[i][col]].size;
			shark[a[i][col]] = 0;
			a[i][col] = 0;
			break;
		}
	}
	int copy_a[104][104];
	memset(copy_a, 0, sizeof(copy_a));

	for (int i = 1; i <= k; i++) {
		if (!shark[i]) continue;
		int y = v[i].y;
		int x = v[i].x;
		int speed = v[i].speed;
		int direction = v[i].direction;
		int ny = y;
		int nx = x;
		while (speed) {
			if (direction == 0) {
				if (speed > ny - 1) {
					speed -= ny - 1;
					ny = 1;
				}
				else {
					ny -= speed;
					speed = 0;
				}
				if (ny == 1) direction ^=1;
			}
			else if (direction == 1) {
				if (speed > n - ny) {
					speed -= n - ny;
					ny = n;
				}
				else {
					ny += speed;
					speed = 0;
				}
				if (ny == n) direction ^= 1;
			}
			else if (direction == 2) {
				if (speed > m - nx) {
					speed -= m - nx;
					nx = m;
				}
				else {
					nx += speed;
					speed = 0;
				}
				if (nx == m) direction ^= 1;
			}
			else {
				if (speed > nx - 1) {
					speed -= nx - 1;
					nx = 1;
				}
				else {
					nx -= speed;
					speed = 0;
				}
				if (nx == 1) direction ^= 1;
			}
		}
		if (copy_a[ny][nx]) {
			if (v[copy_a[ny][nx]].size < v[i].size)
			{
				shark[copy_a[ny][nx]] = 0;
				copy_a[ny][nx] = i;
			}
			else shark[i] = 0;
		}
		else copy_a[ny][nx] = i;

		v[i].y = ny;
		v[i].x = nx;
		v[i].direction = direction;
	}
	memcpy(a, copy_a, sizeof(a));
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= k; i++) {
		cin >> v[i].y >> v[i].x >> v[i].speed >> v[i].direction >> v[i].size;
		v[i].direction--;
		a[v[i].y][v[i].x] = i;
		shark[i] = i;
	}
	for (int i = 1; i <= m; i++) Go(i);
	cout << ret << "\n";
	return 0;
}