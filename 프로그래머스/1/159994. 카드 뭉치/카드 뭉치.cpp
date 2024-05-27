#include <string>
#include <vector>

using namespace std;

string solution(vector<string> cards1, vector<string> cards2, vector<string> goal) {
    string answer = "";
	int cards1Index = 0;
	int cards2Index = 0;
	int totalIndex = 0;

	while (true) {
		if (totalIndex == goal.size()) {
			answer = "Yes";
			break;
		}

		if (cards1Index < cards1.size() && cards1[cards1Index] == goal[totalIndex]) {
			totalIndex++;
			cards1Index++;
		}
		else if (cards2Index < cards2.size() && cards2[cards2Index] == goal[totalIndex]) {
			totalIndex++;
			cards2Index++;
		}
		else {
			answer = "No";
			break;
		}
	}
    return answer;
}