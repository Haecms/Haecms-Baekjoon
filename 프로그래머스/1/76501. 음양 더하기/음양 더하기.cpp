#include <string>
#include <vector>

using namespace std;

int solution(vector<int> absolutes, vector<bool> signs) {
	int answer = 0;
	int count = 0;

	for (bool sign : signs) {
		answer += sign ? absolutes[count++] : -absolutes[count++];
	}
    return answer;
}