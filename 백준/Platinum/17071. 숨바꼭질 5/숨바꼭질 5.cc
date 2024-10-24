#include<iostream>
#include<queue>
using namespace std;
int subin, brother, visited[500004][2], realCnt = -1;
queue<pair<int, int>> q;
int main() {
	cin >> subin >> brother;
	q.push({ subin, 0 });
	int curCnt = 0;
	while (q.size()) {		
		int subinPlace = q.front().first;
		int cnt = q.front().second;
		q.pop();
		if (curCnt != cnt) {
			brother += cnt;
			curCnt = cnt;
			
			if (brother > 500000) {
				realCnt = -1;
				break;
			}
			if ((visited[brother][0] && (visited[brother][0] % 2 == curCnt % 2)) ||
				(visited[brother][1] && (visited[brother][1] % 2 == curCnt % 2))) {
				realCnt = curCnt;
				break;
			}
		}
		if (subinPlace == brother) {
			realCnt = curCnt;
			break;
		}
		for (int i : {subinPlace + 1, subinPlace - 1, subinPlace * 2}) {
			if (i < 0 || i > 500000 || visited[i][(cnt+1) % 2]) continue;
			visited[i][(cnt+1)%2] = cnt + 1;
			q.push({ i, cnt + 1 });
		}
	}
	cout << realCnt << "\n";
	return 0;
}