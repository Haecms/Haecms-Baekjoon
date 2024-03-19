#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

vector<int> solution(vector<int> numbers) {
	unordered_map<int, int> answer_s;
	vector<int> answer;

	for (int i = 0; i < numbers.size(); i++) {
		for (int j = i + 1; j < numbers.size(); j++) {
			if (!answer_s[numbers[i] + numbers[j]]) {
				answer.push_back(numbers[i] + numbers[j]);
			}
			answer_s[numbers[i] + numbers[j]]++;
		}
	}
	sort(answer.begin(), answer.end());
    return answer;
}