#include<iostream>
#include<vector>

using namespace std;

int dy[8] = { -1,-1,-1,0,0,1,1,1 };
int dx[8] = { -1,0,1,-1,1,-1,0,1 };

char c[8][8];
vector<pair<int, int>> queen;
bool flag = true;

bool go() {
	for (auto q : queen) {
		int y = q.first;
		int x = q.second;
		
		for (int i = 0; i < 8; i++) {
			int ny = y;
			int nx = x;
			while (true) {
				ny += dy[i];
				nx += dx[i];
				if (ny < 0 || nx < 0 || ny >= 8 || nx >= 8) break;
				if (c[ny][nx] == '*') { return false; }
			}
		}
	}
	return true;
}

int main() {
	for (int i = 0; i < 8; i++) {
		for (int j = 0; j < 8; j++) { 
			cin >> c[i][j];
			if (c[i][j] == '*') queen.push_back({ i,j });
		}
	}
	if (queen.size() != 8) cout << "invalid";
	else if (go()) cout << "valid";
	else cout << "invalid";

	return 0;
}