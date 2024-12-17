#include<iostream>
using namespace std;
int n,m, visited[21];
string s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> s;
		if (s == "all") {
			for (int i = 1; i < 21; i++) visited[i] = 1; continue;
		}
		else if (s == "empty") {
			for (int i = 1; i < 21; i++) visited[i] = 0; continue;
		}
		cin >> m;
		if (s == "add") visited[m] = 1;
		else if (s == "check") cout << visited[m] << "\n";
		else if (s == "remove") visited[m] = 0;
		else if (s == "toggle") visited[m] ^= 1; 
	}
}