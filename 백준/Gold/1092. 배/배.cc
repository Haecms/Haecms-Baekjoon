#include<iostream>
#include<algorithm>
using namespace std;
int n, crane[51], m, boxes[10001] = {0};
int main() {	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> crane[i];
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		cin >> boxes[i];
	}
	sort(crane, crane + n);
	sort(boxes, boxes + m);
	int cnt = 0;
	int box_max_index = m - 1;
	int removeBoxCount = 0;
	while (true) {
		int box_index = box_max_index;
		cnt++;
		for (int i = n - 1; i >= 0; i--) {
			while (true) {
				if (box_index < 0) break;
				if (boxes[box_index] == 0) {
					box_index--;
					continue;
				}
				if (crane[i] >= boxes[box_index]) {
					boxes[box_index] = 0;
					box_index--;
					removeBoxCount++;
					break;
				}
				else if (i == n - 1 && crane[i] < boxes[m - 1]) {
					cnt = -1;
					break;
				}
				box_index--;
			}
		}
		if (removeBoxCount == m || cnt == -1) break;
	}
	cout << cnt;
}
