#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(string s) {
    int answer = 0;
    unordered_map<char, int> hello;
	char hello2 = '\0';
	string hello3 = "";

	for (int i = 0; i < s.size(); i++) {
		if (hello[s[i]]) {
			hello[s[i]]++;
		}
		else {
			if (hello.size()==1) {
				hello2 = s[i];
			}
			else {
				hello3 += s[i];
			}
			hello[s[i]] = 1;
		}
		int a = hello[hello2];
		for (int j = 0; j < hello3.size(); j++) {
			a -= hello[hello3[j]];
		}
		if (a == 0) {
			hello.clear();
			answer++;
			hello2 = '\0';
			hello3 = "";
		}
	}
	if (hello2) {
		answer++;
	}
    return answer;
}