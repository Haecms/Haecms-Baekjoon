#include<iostream>

using namespace std;

int n, a[6], b;
bool flag = false;

int main() {
    cin >> n;
    
    while(n--) {
        cin >> b;
        a[b]++;
    }
    
    for(int i=1; i<6; i++){
        if(!a[i]) flag = true; 
    }
    
    if(flag) cout << "YES\n";
    else cout << "NO\n";
    
    return 0;
}