#include<iostream>
using namespace std;
int n, a[21];
int main() {
    cin >> n;
    a[1]=1;
    for(int i=2; i<=20; i++) a[i] = a[i-1] + a[i-2];
    cout << a[n] << "\n";
    return 0;
}