#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int main() {
	while (true) {
		stack<char> c;
		getline(cin, s);
		if (s == ".") break;
		for (char a : s) {
			if (a != '(' && a != ')' && a != '[' && a != ']') continue;
			if (c.size() == 0 || a == '(' || a == '[') { c.push(a); continue; }
			else {
				if (c.top() == '(' && a == ')') c.pop();
				else if(c.top() == '[' && a == ']') c.pop();
				else c.push(a);
			}
		}
		c.size() == 0 ? printf("yes\n") : printf("no\n");
	}
}