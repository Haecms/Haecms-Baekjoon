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
                store.push_back(board[y][x]);
                board[y][x] = 0;
                break;
            }
        }
    }
    for (int i = 1; i < store.size(); i++) {
        if ( i> 0 && store[i] == store[i - 1]) {
            answer += 2;
            store.erase(store.begin() + i-1);
            store.erase(store.begin() + i-1);
            i-=2;
        }
    }
    return answer;
}