#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

string solution(vector<string> participant, vector<string> completion) {
    string answer = "";
	unordered_map<string, int> mapCompletion;

	for (int i = 0; i < completion.size(); i++) {
		mapCompletion[completion[i]]++;
	}
	for (int i = 0; i < participant.size(); i++) {
		mapCompletion[participant[i]]--;
		if (mapCompletion[participant[i]] == -1) {
			answer = participant[i];
		}
	}
    return answer;
}