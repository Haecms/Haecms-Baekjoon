#include<iostream>
#include<queue>
using namespace std;
int n, a[3], visited[61][61][61];
int dmg[6][3] = {
	{9,3,1},
	{9,1,3},
	{3,9,1},
	{3,1,9},
	{1,3,9},
	{1,9,3},
};
struct A {
	int a, b, c;
};
queue<A> q;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) cin >> a[i];
	q.push({ a[0], a[1], a[2] });
	while (q.size()) {
		if (visited[0][0][0]) break;
		int one = q.front().a;
		int two = q.front().b;
		int three = q.front().c;
		q.pop();
		for (int i = 0; i < 6; i++) {
			int nOne = max(0, one - dmg[i][0]);
			int nTwo = max(0, two - dmg[i][1]);
			int nThree = max(0, three - dmg[i][2]);
			if (visited[nOne][nTwo][nThree]) continue;
			visited[nOne][nTwo][nThree] = visited[one][two][three] + 1;
			q.push({ nOne ,nTwo ,nThree });
		}
	}
	cout << visited[0][0][0] << "\n";
}