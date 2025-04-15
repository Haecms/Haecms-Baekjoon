#include <string>
#include <vector>
#include <algorithm>
#include <math.h>

using namespace std;
long long solution(int n, vector<int> works) {
    long long answer = 0;
	int bigWork = 0;
	for (int work : works) bigWork += work;
	if (bigWork <= n) return 0;

	sort(works.begin(), works.end(), greater<int>());
	int idx = works.size() ? 1 : 0;
	for (int i = 0; i < n; i++) {
		int &firstValue = works[0];
		if(idx == works.size()) idx = works.size() ? 1 : 0;

		if (firstValue > works[idx]) {
			firstValue--;
			idx = works.size() ? 1 : 0;
		}
		else {
			works[idx]--;
			if (idx != works.size() - 1 && works[idx] < works[idx+1]) idx++;
		}
	}
	for (int work : works) answer += pow(work, 2);
    return answer;
}