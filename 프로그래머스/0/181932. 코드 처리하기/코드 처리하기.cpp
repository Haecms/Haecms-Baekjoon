#include <string>
#include <vector>

using namespace std;

string solution(string code) {
    char mode = '0';
	std::string answer = "";

	for (int i = 0; i < code.size(); i++) {
		if (code[i] == '1') {
			mode = mode == '0' ? '1':'0';
			continue;
		}
		if (mode == '0' && i%2 == 0) {
			answer += code[i];
		}
		else if(mode=='1' && i%2 != 0) {
			answer += code[i];
		}
	}
    if (answer == "") {
	    answer = "EMPTY";
    }
    return answer;
}