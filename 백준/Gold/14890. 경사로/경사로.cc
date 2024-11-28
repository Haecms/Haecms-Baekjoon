#include<iostream>
using namespace std;
int n, m, a[101][101], cnt=0, visitedHeight[101][101], visitedWidth[101][101];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		bool widthCheck = true;
		int prev_widthValue = a[i][0];

		for (int j = 1; j < n; j++) {
			if (prev_widthValue + 1 == a[i][j]) {
				if (j - m >= 0) {
					for (int k = j - m; k < j; k++) {
						if (prev_widthValue != a[i][k] || visitedWidth[i][k]) {
							widthCheck = false;
						}
						visitedWidth[i][k] = 1;
					}
					prev_widthValue = a[i][j];
				}
				else {
					prev_widthValue = a[i][j];
					widthCheck = false;
				}
			}
			else if (prev_widthValue - 1 == a[i][j]) {
				if (j + m <= n) {
					for (int k = j; k < j + m; k++) {
						if (prev_widthValue - 1 != a[i][k] || visitedWidth[i][k]) {
							widthCheck = false;
						}
						visitedWidth[i][k] = 1;
					}
					prev_widthValue = a[i][j];
					j += m - 1;
				}
				else {
					prev_widthValue = a[i][j];
					widthCheck = false;
				}
			}
			else if(prev_widthValue == a[i][j]){
				prev_widthValue = a[i][j];
				continue; 
			}
			else {
				widthCheck = false;
			}
			if (!widthCheck) {
				break;
			}
		}
		bool heightCheck = true;
		int  prev_heightValue = a[0][i];

		for (int j = 1; j < n; j++) {
			if (prev_heightValue + 1 == a[j][i]) {
				if (j - m >= 0) {
					for (int k = j - m; k < j; k++) {
						if (prev_heightValue != a[k][i] || visitedHeight[k][i]) {
							heightCheck = false;
						}
						visitedHeight[k][i] = 1;
					}
					prev_heightValue = a[j][i];
				}
				else {
					prev_heightValue = a[j][i];
					heightCheck = false;
				}
			}
			else if (prev_heightValue -1 == a[j][i]) {
				if (j + m <= n) {
					for (int k = j; k < j + m; k++) {
						if (prev_heightValue-1 != a[k][i] || visitedHeight[k][i]) {
							heightCheck = false;
						}
						visitedHeight[k][i] = 1;
					}
					prev_heightValue = a[j][i];
					j += m -1;
				}
				else {
					prev_heightValue = a[j][i];
					heightCheck = false;
				}
			}
			else if (prev_heightValue == a[j][i]) {
				prev_heightValue = a[j][i];
				continue; 
			}
			else {
				heightCheck = false;
			}
			if (!heightCheck) {
				break;
			}
		}
		if (widthCheck) cnt++;
		if (heightCheck) cnt++;
	}
	cout << cnt << "\n";
}