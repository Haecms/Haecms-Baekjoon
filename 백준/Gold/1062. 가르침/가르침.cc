#include<iostream>
#include<bitset>
using namespace std;
int n, m, cnt = 0, needI = 0, ilist[51];
string s;
void setBitSize(int k, int start, int current) {
	if (k == 0) {
		if ((current & needI) != needI) return;

		int count = 0;
		for (int j = 0; j < n; j++) {
			if ((current & ilist[j]) == ilist[j]) count++;
		}
		cnt = max(cnt, count);
		return;
	}
	for (int i = start; i < 26; i++) {
		setBitSize(k - 1, i + 1, current | (1 << i));
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	needI |= 1 << ('a' - 'a');
	needI |= 1 << ('c' - 'a');
	needI |= 1 << ('i' - 'a');
	needI |= 1 << ('n' - 'a');
	needI |= 1 << ('t' - 'a');
	for (int i = 0; i < n; i++) {
		cin >> s;
		for (char c : s) {
			ilist[i] |= (1 << (c - 'a'));
		}
	}
	setBitSize(m, 0, 0);
	cout << cnt << "\n";
}