#include<iostream>
#include<algorithm>
using namespace std;
int n,y, x, sy=100000000, sx= 100000000, by= -100000000, bx=-100000000;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> y >> x;
		sy = min(y, sy);
		sx = min(x, sx);
		by = max(y, by);
		bx = max(x, bx);
	}
	if (sy == by || sx == bx) cout << 0 << "\n";
	else cout << (by - sy) * (bx - sx) << "\n";
	return 0;
}