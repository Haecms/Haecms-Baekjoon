#include <string>
#include <vector>
#include <unordered_map>
#include <iostream>

using namespace std;

vector<int> solution(vector<string> name, vector<int> yearning, vector<vector<string>> photo) {
    std::vector<int> answer;

	std::unordered_map<std::string, int> myDictionary;
	for (int i = 0; i < name.size(); i++) {
		myDictionary[name[i]] = yearning[i];
	}

	for (int i = 0; i < photo.size(); i++) {
		int j = 0;
		for (const std::string& call_name : photo[i]) {
			if (myDictionary[call_name]) {
				j += myDictionary[call_name];
			}
		}
		answer.push_back(j);
	}
    return answer;
}