#include<bits/stdc++.h>
using namespace std;
int main() {
	int fees[3] = { 0, 0, 0 };
	vector<pair<int, int>> cars;
	int minStart = 1000;
	int maxEnd = -1;
	int realFee = 0;
	for (int i = 0; i < 3; i++) {
		cin >> fees[i];
	}
	for (int i = 0; i < 3; i++) {
		int start, end;
		cin >> start >> end;
		cars.push_back({start, end});
		minStart = start > minStart ? minStart : start;
		maxEnd = end < maxEnd ? maxEnd : end;
	}

	for (int i = minStart; i < maxEnd; i++) {
		int cnt = 0;
		for (auto& car : cars) {
			if (car.first <= i && i < car.second) cnt++;
		}
		if (cnt == 0) continue;
		realFee += cnt == 3 ? fees[2] * 3 : cnt == 2 ? fees[1] * 2 : fees[0];
	}
	cout << realFee;
}