#include <string>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

int solution(int n) {
	vector<int> three;
	while (n > 0) {
		three.push_back(n % 3);
		n /= 3;
	}
	reverse(three.begin(), three.end());

	int answer = 0;

	for (int i = 0; i < three.size(); i++) {
		answer += three[i] * pow(3, i);
	}
    
    return answer;
}