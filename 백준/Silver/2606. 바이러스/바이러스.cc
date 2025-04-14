#include<iostream>
#include<vector>
using namespace std;
vector<int> v[104];
int n, m, a,b, cnt, visited[104];

void go(int idx) {
	visited[idx] = 1;
	for (int vv : v[idx]) {
		if (visited[vv]) continue;
		go(vv);
	}
}

int main() {
	cin >> n >> m;
	while(m--) {
		cin >> a >> b;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	go(1);
	for (int i = 0; i < 104; i++) if (visited[i]) cnt++;
	cout << cnt-1 << "\n";
	return 0;
}