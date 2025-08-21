#include<iostream>
#include<stack>
#include<queue>
using namespace std;
int n, ret=1000000000;
queue<char> q;
stack<char> s;
char c;
int sta(stack<char> st, char start) {
	int cnt = 0;
	while (st.size() && st.top() == start) st.pop();
	while (st.size()) {
		char cur = st.top();
		st.pop();
		if (cur == start) cnt++;
	}
	return cnt;
}
int que(queue<char> qq, char start) {
	int cnt = 0;
	while (qq.size() && qq.front() == start) qq.pop();
	while (qq.size()) {
		char cur = qq.front();
		qq.pop();
		if (cur == start) cnt++;
	}
	return cnt;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> c;
		q.push(c);
		s.push(c);
	}
	ret = min(ret, que(q, 'R'));
	ret = min(ret, que(q, 'B'));
	ret = min(ret, sta(s, 'R'));
	ret = min(ret, sta(s, 'B'));
	cout << ret << "\n";
	return 0;
}