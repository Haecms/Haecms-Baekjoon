#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, int m, vector<int> section) {
	int area = 0;
	int answer = 0;
	for (int i = 0; i < section.size(); i++) {
		if (area < section[i]) {
			answer++;
			area = section[i] + m - 1;
		}
		else {
			continue;
		}
	}
    return answer;
}