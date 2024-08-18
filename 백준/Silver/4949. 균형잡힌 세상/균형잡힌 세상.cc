#include<iostream>
#include<string>
#include<stack>
using namespace std;
string s;
int main() {
	ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
	while (true) {
		stack<char> c;
		getline(cin, s);
		if (s == ".") break;
		for (char a : s) {
			if (a == '(' || a == '[') c.push(a);
			else if (a == ')')
			{
				if (c.empty() || c.top() == '[') { c.push(a); break; }
				if (!c.empty() || c.top() == '(') c.pop();
			}
			else if (a == ']')
			{
				if (c.empty() || c.top() == '(') { c.push(a); break; }
				if (!c.empty() || c.top() == '[') c.pop();
			}
		}
		c.size() == 0 ? cout << "yes\n" : cout << "no\n";
	}
}