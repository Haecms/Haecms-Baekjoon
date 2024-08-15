#include<iostream>
#include<string>
using namespace std;
int n, m, A, B, wA=-1, wB=-1, dA, dB;
string s;
int main() {
    ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> m >> s;
        m == 1 ? A++ : B++;
        int sec = (stoi(string(1, s[0]) + string(1, s[1])) * 60) + stoi(string(1, s[3]) + string(1, s[4]));
        if (A > B && wA < 0) { 
            wA = sec;
        }
        else if (A < B && wB < 0) { 
            wB = sec; 
        }
        else if(A == B){
            if (m == 1) {
                dB += sec - wB;
                wB = -1; 
            }
            else {
                dA += sec - wA;
                wA = -1; 
            }
        }
    }
    if (A == B) {
        printf("%02d:%02d\n", dA / 60, dA % 60);
        printf("%02d:%02d\n", dB / 60, dB % 60);
    }
    else {
        if (wA > 0) dA += 2880 - wA;
        else dB += 2880 - wB;
        printf("%02d:%02d\n", dA / 60, dA % 60);
        printf("%02d:%02d\n", dB / 60, dB % 60);
    }
    return 0;
}