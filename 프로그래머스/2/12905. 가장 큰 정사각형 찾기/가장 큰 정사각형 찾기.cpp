#include <vector>
#include <algorithm>
using namespace std;
int solution(vector<vector<int>> board)
{
	int answer = 1234;
	int a[1002][1002];

	for (int i = 1; i <= board.size(); i++) {
		for (int j = 1; j <= board[i - 1].size(); j++) {
			a[i][j] = a[i - 1][j] + a[i][j - 1] - a[i - 1][j - 1] + board[i - 1][j - 1];
		}
	}

	int size = min(board.size(), board[0].size());
	while (true) {
		for (int i = board.size(); i >= size; i--) {
			for (int j = board[i - 1].size(); j >= size; j--) {
				if (a[i][j] + a[i - size][j - size] - a[i - size][j] - a[i][j - size] == size * size) {
					answer = size * size;
					return answer;
				}
			}
		}
		size--;
	}
}