#include<iostream>
#include<queue>
using namespace std;
int n, m, fastestTime = 0, personVisited[1002][1002], fireVisited[1002][1002];
char currentMap[1002][1002];
queue<pair<int, pair<int, int>>> person;
queue<pair<int, pair<int, int>>> fire;
int dy[4] = { 0, 1, 0, -1 };
int dx[4] = { 1, 0, -1, 0 };

bool personSetting(int y, int x, int count) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > n + 1 || nx > m + 1 || ny < 0 || nx < 0 || personVisited[ny][nx]) continue;
		if (currentMap[ny][nx] == 'F' || currentMap[ny][nx] == '#') continue;
		personVisited[ny][nx] = 1;
		person.push({ count + 1, {ny, nx} });
		currentMap[ny][nx] = 'J';
		if (ny == 0 || nx == 0 || ny == n + 1 || nx == m + 1) return true;
	}
	return false;
}
void fireSetting(int y, int x, int count) {
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny > n || nx > m || ny <= 0 || nx <= 0 || fireVisited[ny][nx]) continue;
		if (currentMap[ny][nx] == 'F' || currentMap[ny][nx] == '#') continue;
		fireVisited[ny][nx] = 1;
		fire.push({ count + 1, {ny, nx} });
		currentMap[ny][nx] = 'F';
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> currentMap[i][j];
			if (currentMap[i][j] == 'J') {
				personVisited[i][j] = 1;
				person.push({ 0, {i,j} });
			}
			else if (currentMap[i][j] == 'F') {
				fireVisited[i][j] = 1;
				fire.push({ 0, {i,j} });
			}
		}
	}
	while (true) {
		if (!person.size()) break;
		int person_count = person.front().first;
		int fire_count;
		if (fire.size()) fire_count= fire.front().first;
		bool personArrive = false;
		while (person.size()) {
			if (person.front().first != person_count) break;
			int y = person.front().second.first;
			int x = person.front().second.second;
			if(currentMap[y][x] != 'F') 
				if(personArrive = personSetting(y, x, person_count)) break;
			person.pop();
		}
		if (personArrive) {
			fastestTime = person_count + 1;
			break;
		}
		while (fire.size()) {
			if (fire.front().first != fire_count) break;
			int y = fire.front().second.first;
			int x = fire.front().second.second;
			fireSetting(y, x, fire_count);
			fire.pop();
		}
	}
	if (fastestTime != 0) cout << fastestTime << "\n";
	else cout << "IMPOSSIBLE";
}