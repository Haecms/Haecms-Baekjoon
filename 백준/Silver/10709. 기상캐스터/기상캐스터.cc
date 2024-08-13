#include<bits/stdc++.h>
using namespace std;
int n, m;
queue<int> visited;
char c;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cnt = -1;
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'c') { visited.push(0); cnt = 0; }
			else if(cnt >= 0) { cnt++; visited.push(cnt); }
			else { visited.push(cnt); }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited.front() << " ";
			visited.pop();
		}
		cout << '\n';
	}
}