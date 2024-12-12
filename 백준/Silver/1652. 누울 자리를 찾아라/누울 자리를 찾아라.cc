#include<iostream>
#include<vector>
using namespace std;
int n, realY, realX;
char c, cm[101][101];
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> cm[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		int yCnt = 0;
		int xCnt = 0;
		vector<int> vx;
		vector<int> vy;
		for (int j = 0; j < n; j++) {
			if (cm[i][j] == '.') { xCnt++; }
			else if (cm[i][j] == 'X') {
				vx.push_back(xCnt);
				xCnt = 0;
			}
			if (cm[j][i] == '.') yCnt++;
			else if (cm[j][i] == 'X') {
				vy.push_back(yCnt);
				yCnt = 0;
			}
		}
		vx.push_back(xCnt);
		vy.push_back(yCnt);
		for (int x : vx) { if (x > 1) realX++; }
		for (int y : vy) { if (y > 1) realY++; }
	}
	cout << realX << " " << realY << "\n";
	
}