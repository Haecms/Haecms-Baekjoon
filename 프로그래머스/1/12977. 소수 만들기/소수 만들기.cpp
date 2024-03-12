#include <vector>
#include <iostream>
#include <unordered_map>
#include <cmath>
using namespace std;

int solution(vector<int> nums) {
	int answer = 0;
	vector<int>hello2;
	

	for (int i = 0; i < nums.size()-2; i++) {
		for (int j = i+1; j < nums.size() - 1; j++) {
			for (int k = j+1; k < nums.size(); k++) {
				int add = nums[i]+ nums[j]+ nums[k];
				hello2.push_back(add);
			}
		}
	}
	for (int i = 0; i < hello2.size(); i++) {
		bool flag = true;
		for (int j = 2; j <= sqrt(hello2[i]); j++) {
			if (hello2[i] % j == 0) {
				flag = false;
				break;
			}
		}
		if (flag) {
			answer++;
		}
	}

    return answer;
}