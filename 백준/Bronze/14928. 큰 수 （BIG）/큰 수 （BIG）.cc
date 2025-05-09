#include<iostream>
using namespace std;
int ret;
char c;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
    while (cin >> c) ret = (ret * 10 + c - '0') % 20000303;
    cout << ret << "\n";
    return 0;
}