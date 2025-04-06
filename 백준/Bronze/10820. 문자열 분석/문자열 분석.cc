#include<iostream>
#include<string>
using namespace std;
string s;
int main() {
	while (getline(cin, s)) {
		int so = 0, dae = 0, no = 0, em = 0;
		for (int i = 0; i < s.size(); i++) {
			if (s[i] >= 'A' && s[i] <= 'Z') dae++;
			else if (s[i] >= 'a' && s[i] <= 'z') so++;
			else if (s[i] == ' ') em++;
			else no++;
		}
		cout << so << " " << dae << " " << no << " " << em << "\n";
	}
	return 0;
}