#include<iostream>
#include<queue>
using namespace std;
priority_queue<int, vector<int>, greater<int>> pq;
int n, m;
int main() {
	ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> m;
		if (m == 0) {
			if (pq.size()) {
				cout << pq.top() << "\n";
				pq.pop();
			}
			else cout << "0" << "\n";
		}
		else pq.push(m);
	}
}