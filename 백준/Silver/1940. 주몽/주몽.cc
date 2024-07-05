#include <bits/stdc++.h>
using namespace std;

int n, m, number, need, ret;
map<int, int> hello;
int main()
{
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> number;
		hello[number]++;
	}
	for (auto c : hello) {
		need = m - c.first;
		if (hello[need] > 0 && hello[c.first] > 0 && need != c.first) {
		    ret++;
		    hello[c.first]--;
		    hello[need]--;
		}
	}
	cout << ret;
}
