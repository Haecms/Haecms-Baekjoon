#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
int n, money, day;
vector<pair<int, int>> v_day_money;
priority_queue<int> pq_money;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for(int i=0; i<n; i++) {
		cin >> money >> day;
		v_day_money.push_back({ day, money });
	}
	sort(v_day_money.begin(), v_day_money.end());
	int ret = 0;
	for (int i = 0; i < n; i++) {
		ret += v_day_money[i].second;
		pq_money.push(-v_day_money[i].second);
		if (pq_money.size() > v_day_money[i].first) {
			ret += pq_money.top();
			pq_money.pop();
		}
	}
	cout << ret;
}