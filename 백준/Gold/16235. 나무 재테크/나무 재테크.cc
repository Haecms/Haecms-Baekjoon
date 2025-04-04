#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, m, k, r, c, d, nutrient[14][14], original_nutrient[14][14], cnt;
int dy[8] = { 0,1,1,1,0,-1,-1,-1 };
int dx[8] = { 1,1,0,-1,-1,-1,0,1 };
vector<int> curMap[14][14];
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> original_nutrient[i][j];
			nutrient[i][j] = 5;
		}
	}
	for (int i = 0; i < m; i++) {
		cin >> r >> c >> d;
		curMap[r][c].push_back(d);
	}
	while (k--) {
		// 봄, 여름
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (curMap[i][j].size() > 1) sort(curMap[i][j].begin(), curMap[i][j].end());
				bool flag = 0;
				for (int t = 0; t < curMap[i][j].size(); t++) {
					if (flag) {
						nutrient[i][j] += curMap[i][j][t] / 2;
						curMap[i][j].erase(curMap[i][j].begin() + t--);
						continue;
					}
					if (nutrient[i][j] < curMap[i][j][t]) {
						nutrient[i][j] += curMap[i][j][t] / 2;
						curMap[i][j].erase(curMap[i][j].begin() + t--);
						flag = 1;
					} else nutrient[i][j] -= curMap[i][j][t], curMap[i][j][t]++;
				}
			}
		}
		// 가을
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				nutrient[i][j] += original_nutrient[i][j]; // 겨울
				if (!curMap[i][j].size()) continue;
				for (int t = 0; t < curMap[i][j].size(); t++) {
					if (curMap[i][j][t] % 5 == 0) {
						for (int z = 0; z < 8; z++) {
							int ny = i + dy[z];
							int nx = j + dx[z];
							if (ny <= 0 || nx <= 0 || ny > n || nx > n) continue;
							curMap[ny][nx].push_back(1);
						}
					}
				}
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cnt += curMap[i][j].size();
		}
	}
	cout << cnt << "\n";
	return 0;
}