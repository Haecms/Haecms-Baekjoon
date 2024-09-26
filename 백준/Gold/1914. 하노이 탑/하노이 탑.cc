#include<iostream>
#include<cmath>
#include<string>
using namespace std;

void Hanoi(int from, int to, int temp, int unit) {
    if (unit == 1) {
        cout << from << " " << to << "\n";
    }
    else {
        Hanoi(from, temp, to, unit - 1);
        cout << from << " " << to << "\n";
        Hanoi(temp, to, from, unit - 1);
    }
}

int main() {
    int n;
    cin >> n;
    string answer = to_string(pow(2, n));
    answer = answer.substr(0, answer.find('.'));
    answer[answer.size() - 1] -= 1;
    
    cout << answer << "\n";
    if (n <= 20) {
        Hanoi(1, 3, 2, n);
    }
}