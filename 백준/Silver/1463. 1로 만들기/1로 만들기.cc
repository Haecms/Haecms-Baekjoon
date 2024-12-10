#include<iostream>
using namespace std;
int n, c=20000000;
void go(int current, int cnt) {
	if (cnt > c) return;
	if (!(current % 3)) go(current / 3, cnt + 1);
	if (!(current % 2)) go(current / 2, cnt + 1);
	if (current > 1) go(current - 1, cnt + 1);
	if (current == 1) {
		c = min(c, cnt);}
}
int main() {
	cin >> n;
	go(n, 0);
	cout << c;
}