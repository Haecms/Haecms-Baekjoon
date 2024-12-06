#include<iostream>
#include<vector>
#include<math.h>
using namespace std;
int n, visitedX[16], cnt = 0, visited[16][16];
vector<pair<int, int>> v;
bool isPossible(int y, int x) {
    for (auto a : v) {
        int ry = a.first;
        int rx = a.second;
        if (!((abs(ry - y)) - (abs(rx - x)))) return false;
    }
    return true;
}
void check(int y, int count) {
    if (count == n) {
        cnt++;
        return;
    }
    for (int i = 0; i < n; i++) {
        if (visitedX[i]) continue;
        if (isPossible(y, i)) {
            visited[y][i] = 1;
            visitedX[i] = 1;
            v.push_back({ y,i });

            check(y + 1, count + 1);

            visited[y][i] = 0;
            visitedX[i] = 0;
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n;
    check(0, 0);
    cout << cnt << "\n";
    return 0;
}