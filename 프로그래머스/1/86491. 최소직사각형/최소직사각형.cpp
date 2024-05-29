#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> sizes) {
	int totalLongSize = 0;
	int totalShortSize = 0;
	for (int i = 0; i < sizes.size(); i++) {
		if (sizes[i][0] > sizes[i][1]) {
			totalLongSize = totalLongSize < sizes[i][0] ? sizes[i][0] : totalLongSize;
			totalShortSize = totalShortSize < sizes[i][1] ? sizes[i][1] : totalShortSize;
		}
		else {
			totalLongSize = totalLongSize < sizes[i][1] ? sizes[i][1] : totalLongSize;
			totalShortSize = totalShortSize < sizes[i][0] ? sizes[i][0] : totalShortSize;
		}
	}
    return totalLongSize * totalShortSize;
}