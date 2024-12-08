#include<iostream>
#include<queue>
using namespace std;
int n, m;
string s;
queue<pair<string, int>> q;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> s >> m;
		q.push({ s, m });
	}
	while (q.size() != 1) {
		string student = q.front().first;
		int num = q.front().second;
		q.pop();
		for (int i = 0; i < num - 1; i++) {
			string nstudetn = q.front().first;
			int nnum = q.front().second;
			q.pop();
			q.push({ nstudetn, nnum });
		}
		q.pop();
	}
	cout << q.front().first << "\n";
	return 0;
}