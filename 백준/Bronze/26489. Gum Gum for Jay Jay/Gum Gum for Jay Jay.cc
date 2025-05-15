#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int main() {
	while (getline(cin, s)) n++;
	cout << n << "\n";
	return 0;
}