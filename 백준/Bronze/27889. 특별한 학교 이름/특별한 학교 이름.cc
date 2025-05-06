#include<iostream>
using namespace std;
string s;
int main() {
    cin >> s;
    if(s == "NLCS") cout << "North London Collegiate School" << "\n";
    else if(s == "BHA")cout << "Branksome Hall Asia" << "\n";
    else if(s == "KIS")cout << "Korea International School" << "\n";
    else cout << "St. Johnsbury Academy" << "\n";
    return 0;
}