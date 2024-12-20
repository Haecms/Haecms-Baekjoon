#include<iostream>
using namespace std;
int n;
string s;
int main() {
    cin >> n;
    while(n--){
        cin >> s;
        int cnt=0, go = 1;
        for(char c : s) {
            if(c=='O') cnt+=go++;
            else go=1;
        } 
        cout << cnt << "\n";
    }
    return 0;
}