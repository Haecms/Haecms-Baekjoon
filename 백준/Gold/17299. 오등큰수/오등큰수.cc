#include<iostream>
#include<stack>
using namespace std;
int n, cnt[1000004], original[1000004], ret[1000004];
stack<int> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> original[i];
		cnt[original[i]]++;
	}
	for (int i = 0; i < n; i++) {
		while (s.size() && cnt[original[s.top()]] < cnt[original[i]]) {
			ret[s.top()] = original[i];
			s.pop();
		}
		s.push(i);
	}
	for (int i = 0; i < n; i++) {
		if (ret[i]) cout << ret[i] << " ";
		else cout << "-1 ";
	}
}