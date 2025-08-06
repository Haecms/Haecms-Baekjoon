#include<iostream>
using namespace std;
int n;
string s;
int go(int start, int end, int cnt) {
	while (start <= end) {
		if (s[start] == s[end]) start++, end--;
		else {
			if (cnt) return 2;
			int rmLeft = go(start + 1, end, cnt + 1);
			int rmRight = go(start, end - 1, cnt + 1);
			return rmLeft > rmRight ? rmRight : rmLeft;
		}
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> s;
		cout << go(0, s.size() - 1, 0) << "\n";
	}
}