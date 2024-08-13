#include<bits/stdc++.h>
using namespace std;
const int mx=104;
int n, m;
int visited[mx][mx];
char c;
void goRight(int y, int x, int k) {
	if (visited[y][x] == 0 || x >= m) return;
	visited[y][x] = k;
	goRight(y, x + 1, k + 1);
}
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> c;
			if(c == 'c') visited[i][j] = 0;
			else visited[i][j] = -1;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if(visited[i][j] == 0 && i < n && j+1 < m) goRight(i, j + 1, 1);
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << visited[i][j] << " ";
		}
		cout << '\n';
	}
}