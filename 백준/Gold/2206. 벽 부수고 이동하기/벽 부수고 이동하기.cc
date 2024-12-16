#include<iostream>
#include<queue>
using namespace std;
int n, m, ma[1004][1004], visitedOriginal[1004][1004], visitedTelepote[1004][1004];
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };
char c;
struct A {
    int y;
    int x;
    char gubun;
};
queue<A> q;
void go() {
    while (q.size()) {
        int y = q.front().y;
        int x = q.front().x;
        int gubun = q.front().gubun;
        if (y == n - 1 && x == m - 1) break;
        q.pop();
        if (gubun == 'N') {
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || visitedOriginal[ny][nx]) continue;
                if (ma[ny][nx]) {
                    q.push({ ny,nx, 'Y' });
                    visitedTelepote[ny][nx] = visitedTelepote[y][x] + 1;
                }
                else {
                    q.push({ ny,nx,'N' });
                    visitedOriginal[ny][nx] = visitedOriginal[y][x] + 1;
                    visitedTelepote[ny][nx] = visitedTelepote[y][x] + 1;
                }
            }
        }
        else {
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;
                if (ny < 0 || nx < 0 || ny >= n || nx >= m || ma[ny][nx] || visitedTelepote[ny][nx]) continue;
                q.push({ ny,nx, 'Y' });
                visitedTelepote[ny][nx] = visitedTelepote[y][x] + 1;
            }
        }
    }
}
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> c;
            ma[i][j] = c - '0';
        }
    }
    visitedOriginal[0][0] = 1;
    visitedTelepote[0][0] = 1;
    q.push({ 0,0,'N' });
    go();
    int cnt = -1;
    if (visitedOriginal[n - 1][m - 1] && visitedTelepote[n - 1][m - 1]) cnt = min(visitedOriginal[n - 1][m - 1], visitedTelepote[n - 1][m - 1]);
    else if (visitedOriginal[n - 1][m - 1] || visitedTelepote[n - 1][m - 1]) cnt = max(visitedOriginal[n - 1][m - 1], visitedTelepote[n - 1][m - 1]);
    cout << cnt << "\n";

}