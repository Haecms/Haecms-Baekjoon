#include<bits/stdc++.h>
using namespace std;
int n, m, a,b, big=0;
vector<int> v[10001];
int visited[10001];
set<int> ret2[10001];

int go(int i, int cnt) {
	visited[i]=1;
	cnt++;
	for (int j = 0; j < v[i].size(); j++) {
		if (visited[v[i][j]] == 1) continue;
		cnt = go(v[i][j], cnt);
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		cin >> a >> b;
		v[b].push_back(a);
	}	
	for (int i = 1; i <= n; i++) {
		memset(visited, 0, sizeof(visited));
		int count = 0;
		if (v[i].size() != 0) {
			count = go(i, count);
			big = max(count, big);
			ret2[count].insert(i);
		}
	}
	for (int a : ret2[big]) {
		cout << a << ' ';
	}
}
