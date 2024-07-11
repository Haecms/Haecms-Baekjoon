#include <bits/stdc++.h>
using namespace std;
int n, cnt;
string s;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> s;

        stack<char> alphabet;
        for(char a : s) {
            if(alphabet.size() && alphabet.top() == a) alphabet.pop();
            else alphabet.push(a);
        }
		if(alphabet.size() == 0) cnt++;
	}
	cout << cnt << "\n";
}