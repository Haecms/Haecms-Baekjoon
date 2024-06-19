#include <bits/stdc++.h>
using namespace std;
int main() {
    int answer = 1;
	string input = "";
	cin >> input;
	string input2 = input;
	reverse(input2.begin(), input2.end());
	if (input2 != input) answer = 0;
	cout << answer;
}