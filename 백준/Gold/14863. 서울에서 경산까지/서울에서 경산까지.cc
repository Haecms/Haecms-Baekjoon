#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int n, k, a,b,c,d, ret;
struct A { int time, money; };
struct B { int idx, time, money; };
vector<A> walk, bicycle;
queue<B> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c >> d;
		walk.push_back({ a,b });
		bicycle.push_back({ c,d });
	}
	q.push({ 0, walk[0].time, walk[0].money });
	q.push({ 0, bicycle[0].time, bicycle[0].money });
	while (q.size()) {
		int idx = q.front().idx;
		int time = q.front().time;
		int money = q.front().money;
		q.pop();
		if (time > k) continue;
		if (idx == n - 1) {
			ret = max(ret, money);
			continue;
		}
		q.push({ idx + 1, time + walk[idx + 1].time, money + walk[idx + 1].money });
		q.push({ idx + 1, time + bicycle[idx + 1].time, money + bicycle[idx + 1].money });
	}
	cout << ret << "\n";
	return 0;
}