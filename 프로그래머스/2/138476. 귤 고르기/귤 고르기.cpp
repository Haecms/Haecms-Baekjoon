#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

int solution(int k, vector<int> tangerine) {
    int answer = 0;
	unordered_map<int, int> size_count;
	vector<int> size;
	vector<int> count;
	unordered_map<int, vector<int>> count_sizes;

	for (int i = 0; i < tangerine.size(); i++) {
		if (size_count[tangerine[i]]) {
			size_count[tangerine[i]]++;
		}
		else {
			size_count[tangerine[i]]++;
			size.push_back(tangerine[i]);
		}

	}

	for (int i = 0; i < size.size(); i++) {
		if (!count_sizes[size_count[size[i]]].size()) {
			count_sizes[size_count[size[i]]].push_back(size[i]);
			count.push_back(size_count[size[i]]);
		}
		else {
			count_sizes[size_count[size[i]]].push_back(size[i]);
		}
		
	}
	sort(count.begin(), count.end(), greater<int>());
	int a = 0;
	for (int i = 0; i < count.size(); i++) {
		bool flag = false;
		for (int j = 0; j < count_sizes[count[i]].size(); j++) {
			a += count[i];
			answer++;
			if (a >= k) {
				flag = true;
				break;
			}
		}
		if (flag) {
			break;
		}
	}
    return answer;
}