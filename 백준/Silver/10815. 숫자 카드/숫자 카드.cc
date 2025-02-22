#include<iostream>
#include<unordered_map>
using namespace std;
unordered_map<int, int> um;
int n, a;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while (n--) {
		cin >> a;
		um[a] = 1;
	}
	cin >> n;
	while (n--) {
		cin >> a;
		cout << um[a] << " ";
	}
	return 0;
}