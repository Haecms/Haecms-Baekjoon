#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(vector<int> array) {
	unordered_map<int, int> hello;
	vector<int> hello2;
	for (int i = 0; i < array.size(); i++) {
		if (!hello[array[i]]) {
			hello2.push_back(array[i]);
		}
		hello[array[i]]++;
	}

	int answer = -1;
	int bigcount = 0;
	if (hello.size() > 1) {
		answer = hello2[0];
		bigcount = hello[hello2[0]];
		for (int i = 0; i < hello.size()-1; i++) {
			if (bigcount < hello[hello2[i+1]]) {
				answer = hello2[i+1];
				bigcount = hello[hello2[i+1]];
			}
		}
	}
	else {
		answer = hello2[0];
	}
	if (answer != -1 && hello.size() > 1) {
		int count = 0;
		for (int i = 0; i < hello.size(); i++) {
			if (bigcount == hello[hello2[i]]) {
				count++;
			}
		}
		if (count > 1) {
			answer = -1;
		}
	}
    return answer;
}