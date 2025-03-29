#include<iostream>
using namespace std;
int ret;
string s;
int main() {
    cin >> s;
    for(int i=0; i<s.size(); i++){
        if(s[i] == 'a' || s[i] == 'e'|| s[i] == 'i'|| s[i] == 'o'|| s[i] == 'u') ret++;
    }
    cout << ret << "\n";
    return 0;
}