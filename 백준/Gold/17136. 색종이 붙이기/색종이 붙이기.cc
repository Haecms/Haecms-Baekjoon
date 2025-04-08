#include<iostream>
#include<algorithm>
using namespace std;
bool a[12][12];
int ret = 1e9, aCnt[6];

void draw(int y, int x, int size, int value) {
	for (int i = y; i <= y + size; i++) {
		for (int j = x; j <= x + size; j++) {
			a[i][j] = value;
		}
	}
}

bool check(int y, int x, int size) {
	for (int i = y; i <= y + size; i++) {
		for (int j = x; j <= x + size; j++) {
			if (!a[i][j]) return false;
		}
	}
	return true;
}

void goDFS(int y, int x, int size, int cnt) {
	if (ret < cnt) return;
	if (aCnt[size] > 5) return;
	if (y >= 10) {
		ret = min(ret, cnt);
		return;
	}
	if (!a[y][x] && x < 10) goDFS(y, x + 1, size, cnt);
	else if (!a[y][x]) goDFS(y + 1, 0, size, cnt);
	for (int i = 4; i >= 0; i--) {
		if (check(y, x, i)) {
			draw(y, x, i, 0);
			aCnt[i]++;
			goDFS(y, x + i, i, cnt + 1);
			aCnt[i]--;
			draw(y, x, i, 1);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) cin >> a[i][j];
	}
	goDFS(0, 0, 0, 0);
	if (ret == 1e9) cout << -1 << "\n";
	else cout << ret << "\n";
	return 0;
}