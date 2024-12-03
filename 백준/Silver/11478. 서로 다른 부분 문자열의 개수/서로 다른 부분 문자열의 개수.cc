#include<iostream>
#include<unordered_set>
#include<string>
using namespace std;
string s;
unordered_set<string> ms;
void pushData(string cs, int index) {
	ms.insert(cs);
	if (index != s.size() - 1) {
		pushData(cs + string(1, s[index + 1]), index + 1);
	}
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> s;
	for (int i = 0; i < s.size(); i++) {
		pushData(string(1,s[i]), i);
	}
	cout << ms.size() << "\n";
}