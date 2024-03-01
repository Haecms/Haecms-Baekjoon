#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

int solution(int n, int m, vector<int> section) {
	unordered_map<int, int> section2;
	int count = 0;
	int answer = 0;

	for (int i = 1; i <= n; i++) {
		if (i == section[count]) {
			count++;
			section2[i] = 1;
		}
		else {
			section2[i] = 0;
		}
	}
	count = 1;
	while (count <= n) {
		if (section2[count]) {
			for (int i = count; i < count + m; i++) {
				section2[i] =0;
			}
			answer++;
		}
		count++;
	}
    return answer;
}