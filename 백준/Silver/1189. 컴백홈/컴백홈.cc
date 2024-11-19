#include <iostream>
using namespace std;
int r, c, k, visited[6][6], ret = 0;
char a[6][6];
int dy[4] = { 0,-1,0,1 };
int dx[4] = { -1,0,1,0 };
void go(int y, int x, int cnt) {
    if (cnt >= k) {
        if (y == 0 && x == c - 1) ret++;
        else return;
    }
    else {
        for (int i = 0; i < 4; i++) {
            int ny = dy[i] + y;
            int nx = dx[i] + x;
            if (ny < 0 || nx < 0 || ny >= r || nx >= c || visited[ny][nx]) continue;
            visited[ny][nx] = 1;
            go(ny, nx, cnt + 1);
            visited[ny][nx] = 0;
        }
    }
    
}
int main()
{
    cin >> r >> c >> k;
    for (int i = 0; i < r; i++) {
        for (int j = 0; j < c; j++) {
            cin >> a[i][j];
            if (a[i][j] == 'T') visited[i][j] = 1;
        }
    }
    visited[r - 1][0] = 1;
    go(r-1, 0, 1);
    cout << ret << "\n";
}