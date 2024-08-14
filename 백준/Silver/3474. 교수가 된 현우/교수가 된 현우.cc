#include<iostream>
using namespace std;
int n, m;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m;
		int divide = 5, ret = 0;
		while (m >= divide) { ret += m / divide; divide *= 5; }
		cout << ret << "\n";
	}
}