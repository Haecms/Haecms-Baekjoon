#include<iostream>
using namespace std;
int n, m, a, ma[54][54], visited[54][54], cnt2, changeCnt, area[1000004];
int dy[4] = { 0, -1, 0, 1 };
int dx[4] = { -1, 0, 1, 0 };
void go(int y, int x, int count) {
    changeCnt++;
    visited[y][x] = count;
    int binary = ma[y][x];
    for (int i = 0; i < 4; i++) {
        if (!(binary & (1 << i))) {
            int ny = y + dy[i];
            int nx = x + dx[i];
            if (ny < 0 || nx < 0 || ny >= m || nx >= n || visited[ny][nx]) continue;
            go(ny, nx, count);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> ma[i][j];
        }
    }
    int cnt1 = 0;
    int areaCnt = 1;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (!visited[i][j]) {
                changeCnt = 0;
                go(i, j, areaCnt);
                cnt1++;
                cnt2 = max(changeCnt, cnt2);
                area[areaCnt++] = changeCnt;
            }
        }
    }
    int cnt3 = 0;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < 4; k++) {
                int ny = dy[k] + i;
                int nx = dx[k] + j;
                if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
                if (visited[i][j] != visited[ny][nx]) {
                    cnt3 = max(cnt3, area[visited[i][j]] + area[visited[ny][nx]]);
                }
            }
        }
    }
    cout << cnt1 << "\n";
    cout << cnt2 << "\n";
    cout << cnt3 << "\n";
}