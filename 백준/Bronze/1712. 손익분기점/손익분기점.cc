#include<iostream>
using namespace std;
int main() {
    int a,b,c;
    cin >> a >> b >> c;
    if(c-b < 1) cout << -1 << "\n";
    else cout << a / (c-b) + 1 << "\n";
    return 0;
}