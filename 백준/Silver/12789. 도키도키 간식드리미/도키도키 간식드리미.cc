#include<iostream>
#include<vector>
#include<stack>
using namespace std;
int main() {
	vector<int> v;
	stack<int> st;
	int n, m;
	cin >> n;
	while (n--) {
		cin >> m;
		if (m == v.size() + 1) v.push_back(m);
		else st.push(m);
		while (st.size() && st.top() == v.size() + 1) {
			v.push_back(st.top());
			st.pop();
		}
	}
	if (st.size()) cout << "Sad" << "\n";
	else cout << "Nice" << "\n";
	return 0;
}