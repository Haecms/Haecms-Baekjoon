#include <vector>
#include <iostream>
#include <stack>

using namespace std;

vector<int> solution(vector<int> arr) 
{
    stack<int> hello;
	vector<int>answer;

	for (int i = 0; i < arr.size(); i++) {
		if (i == 0) {
			hello.push(arr[i]);
			answer.push_back(arr[i]);
		}
		else {
			if (hello.top() != arr[i]) {
				hello.push(arr[i]);
				answer.push_back(arr[i]);
			}
		}
	}

    return answer;
}