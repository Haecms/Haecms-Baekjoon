#include<iostream>
#include<stack>
using namespace std; 
stack<int> st;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	int n, a;
	string s;
	cin >> n;
	while (n--) {
		cin >> s;
		if (s[0] == 'p' && s[1] == 'u') {
			cin >> a;
			st.push(a);
		}
		else if (s[0] == 't') {
			if (st.size()) cout << st.top() << "\n";
			else cout << -1 << "\n";
		}
		else if (s[0] == 's') cout << st.size() << "\n";
		else if (s[1] == 'o') { 
			if (st.size()) {
				cout << st.top() << "\n";
				st.pop();
			}
			else cout << -1 << "\n";
		}
		else if (s[0] == 'e') {
			if (st.size()) cout << 0 << "\n";
			else cout << 1 << "\n";
		}
	}
}