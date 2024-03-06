#include <string>
#include <vector>

using namespace std;

int solution(int storey) {
    int answer = 0;
	while (storey > 0) {
		if (storey >= 100) {
			if (storey % 100 > 50) {
				if (storey % 10 >= 5) {
					answer += (10 - storey % 10);
					storey += (10 - storey % 10);
				}
				else {
					answer += storey % 10;
					storey -= storey % 10;
				}
			}
			else {
				if (storey % 10 > 5) {
					answer += (10 - storey % 10);
					storey += (10 - storey % 10);
				}
				else {
					answer += storey % 10;
					storey -= storey % 10;
				}
			}
		}
		else {
			if (storey % 10 > 5) {
				answer += (10 - storey % 10);
				storey += (10 - storey % 10);
			}
			else {
				answer += storey % 10;
				storey -= storey % 10;
			}
		}
		storey /= 10;
	}
    return answer;
}