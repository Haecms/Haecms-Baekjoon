#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int main() {
    ios_base::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	while (true) {
		stack<char> c;
		getline(cin, s);
		if (s == ".") break;
		for (char a : s) {
			if (a != '(' && a != ')' && a != '[' && a != ']') continue;
			if (c.size() == 0 && (a == ']' || a == ')')) { c.push(a); break; }
			if (a == '(' || a == '[') { c.push(a); continue; }
			else {
				if (c.top() == '(' && a == ')') c.pop();
				else if (c.top() == '[' && a == ']') c.pop();
				else break; 
			}
		}
		c.size() == 0 ? cout<<"yes\n" : cout << "no\n";
	}
}