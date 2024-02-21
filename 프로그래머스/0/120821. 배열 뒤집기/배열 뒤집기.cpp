#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<int> num_list) {
    vector<int> answer(num_list.size());
    int count = 0;
	for (int i = num_list.size()-1; i >= 0; i--) {
		answer[count] = num_list[i];
		count++;
	}
    return answer;
}