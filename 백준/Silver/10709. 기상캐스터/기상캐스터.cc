#include<bits/stdc++.h>
using namespace std;
const int mx=104;
int n, m;
int visited[mx][mx];
char c;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cnt = -1;
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'c') { visited[i][j] = 0; cnt = 0; }
			else if(cnt >= 0) { cnt++; visited[i][j] = cnt; }
			else { visited[i][j] = cnt; }
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
}