#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;
string s, ss, ret;
stack<char> st;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s >> ss;
	for (char c : s) {
		st.push(c);
		if (st.size() >= ss.size() && st.top() == ss[ss.size() - 1]) {
			string sss = "";
			for (char cc : ss) {
				sss += st.top(); st.pop();
			}
			reverse(sss.begin(), sss.end());
			if (ss != sss) {
				for (char ccc : sss) st.push(ccc);
			}
		}
	}
	if (!st.size()) cout << "FRULA" << "\n";
	else {
		while (st.size()) {
			ret += st.top(); st.pop();
		}
		reverse(ret.begin(), ret.end());
		cout << ret << "\n";
	}
}