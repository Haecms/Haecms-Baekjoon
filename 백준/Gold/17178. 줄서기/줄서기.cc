#include<iostream>
#include<string>
#include<map>
#include<vector>
#include<algorithm>
#include<queue>
#include<stack>
using namespace std;
int n;
string s;
bool check = true;
map<string, vector<int>> m;
queue<string> q;
stack<string> st;

string split(string s, int index) {
	int place = s.find("-");
	if (index == 0)  return s.substr(0, place); 
	else return s.substr(place+1, s.size() - 1); 
}
bool sortDesc(int a, int b) {
	return a > b;
}
int main() {
	cin >> n;
	while (n--) {
		for (int i = 0; i < 5; i++) {
			cin >> s;
			q.push(s);
			m[split(s, 0)].push_back(stoi(split(s, 1)));
		}
	}
	for (auto a : m) { sort(m[a.first].begin(), m[a.first].end(), sortDesc); }

	while ((q.size() || st.size() && check)) {
		for (auto a : m) {
			if (a.second.size() == 0) continue;
			if (st.size() > 0 && split(st.top(),0) == a.first && stoi(split(st.top(), 1)) == a.second.back()) {
				m[a.first].pop_back();
				st.pop();
				break;
			}
			if (!q.size() && st.size()) { 
				check = false;
				break; 
			}
			if (a.first != split(q.front(), 0) || a.second.back() != stoi(split(q.front(), 1))) {
				st.push(q.front());
				q.pop();
				break;
			}
			q.pop();
			m[a.first].pop_back();
			break;
		}
	}
	if (st.size() == 0) cout << "GOOD";
	else cout << "BAD";
}