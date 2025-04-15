#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
	int bigWork = 0;
	int smallWork = 0;
	for (int a : works) bigWork += a;
	if (n >= bigWork) return 0;
	int bestWork = 0;
	while (smallWork <= bigWork) {
		long long middleWork = (smallWork + bigWork) / 2;
		long long sum_diff = 0;
		for (int work : works) {
			if (work > middleWork) sum_diff += work - middleWork;
		}
		if (sum_diff > n) smallWork = middleWork + 1;
		else {
			bigWork = middleWork - 1;
			bestWork = middleWork;
		}
	}
	for (int& work : works) {
		if (work > bestWork) {
			n -= (work - bestWork);
			work = bestWork;
		}
	}
    sort(works.begin(), works.end(), greater<int>());
	while (n) works[n-- -1]--;
	for (int work : works) answer += pow(work, 2);
    return answer;
}