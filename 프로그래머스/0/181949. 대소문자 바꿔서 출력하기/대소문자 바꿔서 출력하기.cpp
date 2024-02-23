#include <iostream>
#include <string>

using namespace std;

int main(void) {
    string str;
    cin >> str;
    string answer = "";
    for(int i=0; i<str.size(); i++){
        answer += static_cast<int>(str[i]) >= 97 ? char(static_cast<int>(str[i]) - 32) : char(static_cast<int>(str[i]) + 32);
    }
    cout<<answer;
    return 0;
}