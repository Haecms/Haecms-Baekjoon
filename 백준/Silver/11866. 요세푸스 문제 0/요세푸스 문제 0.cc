#include<iostream>
#include<queue>
using namespace std;
int n, m;
queue<int>q;
queue<int> ret;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		q.push(i);
	}
	while (q.size()) {
		for (int i = 0; i < m - 1; i++) {
			int value = q.front();
			q.pop();
			q.push(value);
		}
		ret.push(q.front());
		q.pop();
	}
	cout << "<" << ret.front();
	ret.pop();
	while (ret.size()) {
		cout << ", " << ret.front();
		ret.pop();
	}
	cout << ">";
}