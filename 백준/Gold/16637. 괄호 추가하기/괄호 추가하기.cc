#include<iostream>
#include<vector>
using namespace std;
int n, ret = -987654321;
char c;
vector<int> num;
vector<char> ch;

int calculate(char a, int b, int c) {
	if (a == '+') return b + c;
	else if (a == '-') return b - c;
	else if (a == '*') return b * c;
}

void go(int here, int _num) {
	if (here == ch.size()) {
		ret = max(ret, _num);
		return;
	}
	go(here + 1, calculate(ch[here], _num, num[here + 1]));
	if (here + 2 <= ch.size()) {
		int temp = calculate(ch[here + 1], num[here + 1], num[here + 2]);
		go(here + 2, calculate(ch[here], _num, temp));
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> c;
		if (i % 2)ch.push_back(c);
		else num.push_back(c - '0');
	}
	go(0, num[0]);
	cout << ret << "\n";
}