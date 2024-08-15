#include<iostream>
#include<string>
using namespace std;
int n;
int main() {
    cin >> n;
    int i=666;
    while(n){
        if(to_string(i).find("666") != string::npos) n--; i++;
    }
    cout << i-1 << '\n';
}