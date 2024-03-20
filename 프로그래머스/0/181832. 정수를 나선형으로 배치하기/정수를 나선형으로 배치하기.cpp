#include <string>
#include <vector>

using namespace std;

vector<vector<int>> solution(int n) {
    vector<vector<int>> answer(n, vector<int>(n));

    int i = 0;
    int j = 0;
    answer[i][j] = 1;
    int count = 2;

	while (count <= n * n) {
		while (j + 1 < n && answer[i][j + 1] == 0) {
			j++;
			answer[i][j] = count;
			count++;
		}
		while (i + 1 < n && answer[i + 1][j] == 0) {
			i++;
			answer[i][j] = count;
			count++;
		}
		while (j - 1 >= 0 && answer[i][j - 1] == 0) {
			j--;
			answer[i][j] = count;
			count++;
		}
		while (i - 1 >= 0 && answer[i - 1][j] == 0) {
			i--;
			answer[i][j] = count;
			count++;
		}
	}
    return answer;
}