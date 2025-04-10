#include<iostream>
#include<map>
#include<vector>
using namespace std;
int n, m, a, b, visited[101], ret;
map<int, vector<int>> ma;
void go(int curPoint) {
	visited[curPoint] = 1;
	for (int a : ma[curPoint]) {
		if (!visited[a]) go(a);
	}
}
int main() {
	cin >> n >> m;
	while (m--) {
		cin >> a >> b;
		ma[a].push_back(b);
		ma[b].push_back(a);
	}
	go(1);
	for (int i = 1; i <= 100; i++)  ret += visited[i]; 
	cout << ret-1 << "\n";
	return 0;
}