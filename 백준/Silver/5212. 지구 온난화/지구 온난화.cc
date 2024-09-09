#include<stdio.h>
#include<vector>
using namespace std;
int n, m, maxY=0, minY=100, maxX=0, minX=100;
char a[11][11], newA[11][11], s[12];
int dy[4] = { -1, 0, 1, 0 };
int dx[4] = { 0, 1, 0, -1 };
char check(int y, int x) {
	int cnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || nx < 0 || ny >= n || nx >= m || a[ny][nx] == '.') cnt++;
	}
	return cnt >= 3 ? true : false;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", &s, sizeof(s));
		for (int j = 0; j < m; j++) {
			a[i][j] = s[j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == '.') newA[i][j] = '.';
			else {
				if (check(i, j)) { newA[i][j] = '.'; }
				else {
					newA[i][j] = 'X';
					if (i > maxY) maxY = i;
					if (j > maxX) maxX = j;
					if (i < minY) minY = i;
					if (j < minX) minX = j;
				}
			}
		}
	}
	for (int i = minY; i <= maxY; i++) {
		for (int j = minX; j <= maxX; j++) {
			printf("%c", newA[i][j]);
		}
		printf("\n");
	}
	if (maxY == 0 && minY == 100 && maxX == 0 && minX == 100) printf("X");
	
}