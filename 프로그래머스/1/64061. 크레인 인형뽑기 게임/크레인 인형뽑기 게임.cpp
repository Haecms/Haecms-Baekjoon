#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> store;

    for (int i = 0; i < moves.size(); i++) {
        int x = moves[i] - 1;
        for (int y = 0; y < board.size(); y++) {
            if (board[y][x] != 0) {
                if (store.size() > 0 && store[store.size() - 1] == board[y][x]) {
                    store.erase(store.begin() + (store.size() - 1));
                    answer += 2;
                }
                else {
                    store.push_back(board[y][x]);
                }
                board[y][x] = 0;
                break;
            }
        }
    }
    return answer;
}