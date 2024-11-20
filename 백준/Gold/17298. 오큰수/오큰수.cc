#include<iostream>
#include<stack>
using namespace std;
int n, a, arr[1000004];
stack<pair<int,int>> s;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> a;
		while (s.size() && a > s.top().first) {
			arr[s.top().second] = a;
			s.pop();
		}
		s.push({ a,i });
	}
	for (int i = 0; i < n; i++) {
		if (arr[i] == 0) cout << "-1 ";
		else cout << arr[i] << " ";
	}
}