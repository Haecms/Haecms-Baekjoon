#include<iostream>
#include<vector>
using namespace std;
int n, t, k, s, e, max_satisfy_score = 0, max_time=0;
vector<pair<int, int>> v;
vector<pair<int, int>> good_time;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> t;
	for (int i = 0; i < n; i++) {
		cin >> k;
		while (k--) {
			cin >> s >> e;
			v.push_back({ s, e });
			if (e > max_time) max_time = e;
		}
	}
	int start_time = 0;
	while (start_time + t <= max_time) {
		int satisfy_score = 0;
		int end_time = start_time + t;
		for (auto time : v) {
			int study_start_time = max(start_time, time.first);
			int study_end_time = min(end_time, time.second);
			if (study_start_time < study_end_time && study_start_time < end_time) {
				satisfy_score += study_end_time - study_start_time;
			}
		}
		if (max_satisfy_score < satisfy_score) {
			max_satisfy_score = satisfy_score;
			if (good_time.size() > 0) good_time.pop_back();
			good_time.push_back({ start_time, end_time });
		}
		start_time++;
	}
	cout << good_time[0].first << " " << good_time[0].second << "\n";
}