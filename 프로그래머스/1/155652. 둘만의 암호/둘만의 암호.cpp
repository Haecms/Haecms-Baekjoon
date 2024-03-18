#include <iostream>




using namespace std;

string solution(string s, string skip, int index) {
	string answer;
	for (int i = 0; i < s.size(); i++) {
		int count = 1;
		
		for(int k=1; k<=index; k++){
			bool flag = true;
			int hello = s[i] + count;
			for (int j = 0; j < skip.size(); j++) {
				
				while (hello > 122) {
					hello -= 26;
				}
				if (hello == skip[j]) {
					count++;
					k--;
					flag = false;
					break;
				}
			}
			if (flag) {
				count++;
			}
			if (k == index) {
				answer += hello;
			}
		}
	}
    return answer;
}