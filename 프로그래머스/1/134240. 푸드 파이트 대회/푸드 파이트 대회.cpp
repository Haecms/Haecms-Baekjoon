#include <string>
#include <vector>

using namespace std;

string solution(vector<int> food) {
    vector<int> hello = { 0 };
    for (int i = food.size()-1; i >= 1; i--) {

	    for (int j = 0; j < food[i] / 2; j++) {
		    hello.push_back(i);
		    hello.insert(hello.begin(), i);
	    }
    }
    string answer = "";
    for (int i = 0; i < hello.size(); i++) {
	    answer += to_string(hello[i]);
    }
    
    return answer;
}