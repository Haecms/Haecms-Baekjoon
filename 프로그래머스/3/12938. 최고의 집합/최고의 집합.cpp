#include <string>
#include <vector>

using namespace std;

vector<int> solution(int n, int s) {
    vector<int> answer;
    if (n > s) answer.push_back(-1);
	else {
		int a = s / n;
		int b = s%n;
		vector<int> iv;
		for (int i = 0; i < n; i++) iv.push_back(a);
		for (int i = 0; i < b; i++) iv[i]++;
		for (int i = iv.size() - 1; i >= 0; i--) answer.push_back(iv[i]);
	}
    return answer;
}