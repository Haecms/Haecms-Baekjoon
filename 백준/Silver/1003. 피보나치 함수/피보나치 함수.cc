#include<iostream>
#include<vector>
using namespace std;
int t, N;
vector<pair<int, int>> v;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    v.push_back({ 1, 0 });
    for (int i = 1; i < 41; i++) {
        int first = v[i-1].second;
        int second = v[i-1].first + v[i-1].second;
        v.push_back({ first, second });
    }
    cin >> t;
    while (t--) {
        cin >> N;
        cout << v[N].first << " " << v[N].second << "\n";
    }
}

