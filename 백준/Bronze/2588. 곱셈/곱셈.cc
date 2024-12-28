#include<iostream>
#include<string>
using namespace std;
int n;
string s;
int main() {
    cin >> n >> s;
    for (int i = 2; i >= 0; i--) {
        cout << n * (s[i] - '0') << "\n";
    }
    cout << n * stoi(s) << "\n";
}