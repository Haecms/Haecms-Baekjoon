#include<iostream>
using namespace std;
string s;
int ret;
int main() {
    cin >> s;
    for(int i=0; i<s.size(); i++){
        ret = (ret * 10 + s[i]-'0') % 20000303;
    }
    cout << ret << "\n";
    return 0;
}