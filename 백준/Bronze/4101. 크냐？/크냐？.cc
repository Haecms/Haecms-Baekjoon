#include<iostream>
using namespace std;
int a,b;
int main() {
    while(1){
        cin >> a >> b;
        if(!a && !b) break;
        cout << (a > b ? "Yes" : "No") << "\n";
    }
    return 0;
}