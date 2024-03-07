#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
	for (int i = 0; i < commands.size(); i++) {
		vector<int> hello = array;
		hello.erase(hello.begin() + commands[i][1], hello.end());
		hello.erase(hello.begin(), hello.begin() + commands[i][0]-1);
		sort(hello.begin(), hello.end());
		answer.push_back(hello[commands[i][2] - 1]);
	}
    return answer;
}