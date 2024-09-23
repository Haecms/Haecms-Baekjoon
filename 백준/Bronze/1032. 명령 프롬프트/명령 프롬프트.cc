#include<iostream>
using namespace std;
int n;
string newS, oldS="";
int main() {
	cin >> n;
	cin >> oldS;
	while (--n) {
		cin >> newS;
		for (int i = 0; i < newS.size(); i++) {
			if (newS[i] != oldS[i]) oldS[i] = '?';
		}
	}
	cout << oldS << "\n";
}
