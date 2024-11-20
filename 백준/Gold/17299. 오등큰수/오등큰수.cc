#include<iostream>
#include<stack>
using namespace std;
int n, a, cnt[1000004], original[1000004], ret[1000004];
stack<pair<int,int>> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		original[i] = a;
		cnt[a]++;
	}
	for (int i = 0; i < n; i++) {
		while (s.size() && cnt[s.top().first] < cnt[original[i]]) {
			ret[s.top().second] = original[i];
			s.pop();
		}
		s.push({ original[i],i });
	}
	for (int i = 0; i < n; i++) {
		if (ret[i]) cout << ret[i] << " ";
		else cout << "-1 ";
	}
}