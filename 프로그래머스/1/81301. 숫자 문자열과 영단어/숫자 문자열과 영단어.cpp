#include <string>
#include <vector>

using namespace std;

int solution(string s) {
	string answer = "";
	string compare = "";

	for (int i = 0; i < s.size(); i++) {
		// 숫자일 때
		if (static_cast<int>(s[i]) <= 90) {
			answer += s[i];
			continue;
		}
		else {
			compare += s[i];
			if (compare.size() >= 3) {
				if (compare == "zero") { answer += "0";  compare = ""; }
				if (compare == "one") { answer += "1";  compare = ""; }
				if (compare == "two") { answer += "2";  compare = ""; }
				if (compare == "three") { answer += "3";  compare = ""; }
				if (compare == "four") { answer += "4";  compare = ""; }
				if (compare == "five") { answer += "5";  compare = ""; }
				if (compare == "six") { answer += "6";  compare = ""; }
				if (compare == "seven") { answer += "7";  compare = ""; }
				if (compare == "eight") { answer += "8"; compare = ""; }
				if (compare == "nine") { answer += "9"; compare = ""; }
			}
		}
	}
    return stoi(answer);
}