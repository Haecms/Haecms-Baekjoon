#include<bits/stdc++.h>
using namespace std;
int n, m;
char c;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int cnt = -1;
		for (int j = 0; j < m; j++) {
			cin >> c;
			if (c == 'c') { cout << "0" << " "; cnt = 0; }
			else if (cnt >= 0) { cnt++;  cout << cnt << " "; }
			else { cout << cnt << " "; }
		}
		cout << '\n';
	}
}