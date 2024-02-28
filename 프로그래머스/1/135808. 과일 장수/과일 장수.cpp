#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int k, int m, vector<int> score) {
    int answer = 0;
	int max_count = 0;

	unordered_map<int, int> Dict;
	

	for (int i = 0; i < score.size(); i++) {
		if (score[i] > max_count) {
			max_count = score[i];
		}
		if (Dict[score[i]]) {
			Dict[score[i]]++;
		}
		else {
			Dict[score[i]] = 1;
		}
	}
	int low_Number = 0;
	int count = 0;

	for (int i = 0; i < score.size(); i++) {
		if (!Dict[max_count]) {
			if (max_count == 0) {
				break;
			}
			max_count--;
		}
		while (!Dict[max_count]) {
			max_count--;
		}

		low_Number = max_count;
		Dict[max_count]--;
		count++;

		if (count == m) {
			answer += (low_Number * m);
			count = 0;
		}
	}
    return answer;
}