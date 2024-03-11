#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> lottos, vector<int> win_nums) {
	vector<int> answer;

	unordered_map<int, int> hello;

	sort(win_nums.begin(), win_nums.end());
	
	for (int i = 0; i <= 45; i++) {
		hello[i] = 0;
	}
	for (int i = 0; i < lottos.size(); i++) {
		hello[lottos[i]]++;
	}
	int count = 0;
	for (int i = 0; i < win_nums.size(); i++) {
		for (int j = 1; j < hello.size(); j++) {
			if (hello[j] && j == win_nums[i]) {
				count++;
				break;
			}
		}
	}
	if (count == 6) { answer.push_back(1); }
	if (count == 5) { answer.push_back(2); }
	if (count == 4) { answer.push_back(3); }
	if (count == 3) { answer.push_back(4); }
	if (count == 2) { answer.push_back(5); }
	if (count == 1) { answer.push_back(6); }
	if (count == 0) { answer.push_back(6); }
	answer.insert(answer.begin(), answer[0] - hello[0] == 0 ? 1 : answer[0] - hello[0]);
    return answer;
}