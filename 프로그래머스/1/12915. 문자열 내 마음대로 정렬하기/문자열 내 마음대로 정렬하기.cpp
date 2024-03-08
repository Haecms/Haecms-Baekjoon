#include <string>
#include <vector>

using namespace std;

vector<string> solution(vector<string> strings, int n) {
	vector<char> hello;
	vector<string> answer;

	for (int i = 0; i < strings.size(); i++) {
		hello.push_back(strings[i][n]);
		answer.push_back(strings[i]);
	}
	for (int i = 0; i < hello.size(); i++) {
		for (int j = i+1; j < hello.size(); j++) {
			if (hello[i] > hello[j]) {
				char temp = hello[i];
				hello[i] = hello[j];
				hello[j] = temp;
				string sTemp = answer[i];
				answer[i] = answer[j];
				answer[j] = sTemp;
			}
		}
	}
	for (int i = 0; i < answer.size(); i++) {
		for (int j = i+1; j < answer.size(); j++) {
			if (hello[i] == hello[j]) {
				if (answer[i] > answer[j]) {
					string sTemp = answer[i];
					answer[i] = answer[j];
					answer[j] = sTemp;
				}
			}
			else {
				break;
			}
		}
	}
    return answer;
}