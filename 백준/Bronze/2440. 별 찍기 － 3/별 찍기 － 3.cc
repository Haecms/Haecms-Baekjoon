#include<iostream>
using namespace std;
int main() {
    int n;
    cin >> n;
    while(n){
        for(int i=n; i>0; i--){
            cout << "*";
        }
        cout << "\n";
        n--;
    }
    return 0;
}