#include<iostream>
#include<queue>
#include<string>
#include<math.h>
using namespace std;
// decimal의 경우 소수면 0, 아닐 경우 1
int t, a , b, decimal[10000], visited[10000];
queue<int> q;
void setDecimal(int start, int plus) {
	int value = start;
	while (value < 10000) {
		decimal[value] = 1;
		value += plus;
	}
}
bool isDecimal(int d) {
	for (int i = 2; i < sqrt(d); i++) {
		if (!(d % i)) return false;
	}
	return true;
}
int main() {
	cin >> t;
	for (int i = 2; i < 10000; i++) {
		if (decimal[i]) continue;
		else {
			if (isDecimal(i)) { setDecimal(i + i, i); }
			else { setDecimal(i, i); }
		}
	}
	while (t--) {
		cin >> a >> b;
		q.push(a);
		int cnt = 0;
		bool flag = false;
		while (q.size()) {
			queue<int> q2;
			q2 = q;
			cnt++;
			while (q2.size()) {
				int temp = q2.front();
				q2.pop(); q.pop();
				if (temp == b) {
					flag = true;
					break;
				}
				visited[temp] = 1;
				for (int i = 0; i < 4; i++) {
					for (int j = 0; j < 10; j++) {
						string stemp = to_string(temp);
						stemp[i] = j + '0';
						if (stoi(stemp) < 1000) continue;
						else if (visited[stoi(stemp)]) continue;
						else if (decimal[stoi(stemp)]) continue;
						visited[stoi(stemp)] = 1;
						q.push(stoi(stemp));
					}
				}
			}
			if (flag) break;
		}
		while (q.size()) q.pop();
		for (int i = 0; i < 10000; i++) visited[i] = 0;
		if (flag) cout << cnt - 1 << "\n";
		else cout << "Impossible" << "\n";
	}
}