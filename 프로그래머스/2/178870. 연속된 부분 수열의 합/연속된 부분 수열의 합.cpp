#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

vector<int> solution(vector<int> sequence, int k) {
    	int preIndex = 0;
int proIndex = 0;
long sum = 0;
int minLength = 222222222;
vector<int> answer = { -1,-1 };

while (true) {
	if (sum >= k) {
		if (sum == k && (proIndex - preIndex < minLength)) {
			minLength = proIndex - preIndex;
			answer[0] = preIndex;
			answer[1] = proIndex-1;

		}
		sum -= sequence[preIndex++];
	}
	else {
		if (proIndex == sequence.size()) break;
		sum += sequence[proIndex++];
	}
}
    return answer;
}