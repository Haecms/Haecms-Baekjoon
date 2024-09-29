#include<iostream>
#include<map>
#include<algorithm>
using namespace std;
string s;
map<string, int> color;
string hello[4];

bool ssort(string a, string b) {
	return a < b;
}
int main() {
	for (int i = 0; i < 4; i++) {
		cin >> s;
		if (!color[s]) {
			color[s] = 1;
			hello[i] = s;
		}
	}
	sort(hello, hello + 4, ssort);
	for (int i = 0; i < 4; i++) {
		if (hello[i] == "") continue;
		for (int j = 0; j < 4; j++) {
			if (hello[j] == "") continue;
			cout << hello[i] << " " << hello[j] << "\n";
		}
	}
}