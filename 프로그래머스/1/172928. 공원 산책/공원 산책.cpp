#include <string>
#include <vector>

using namespace std;

bool checkGo(char direction, int move, int x, int y);
int map[50][50];

void initializeMap() {
    // 맵 제외 영역은 7로 초기화
    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j < 50; ++j) {
            map[i][j] = 7;
        }
    }
}

vector<int> solution(vector<string> park, vector<string> routes) {
    vector<int> answer;
    // 행, 열
    int rows = park.size();
    int cols = park[0].size();
    // 현재 x y 좌표
    int x;
    int y;

    initializeMap();

    // 0 장애물, 1 안전지대
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (park[i][j] == 'S') {
                y = i;
                x = j;
                map[i][j] = 1;
            } else if (park[i][j] == 'X') {
                map[i][j] = 0;
            } else {
                map[i][j] = 1;
            }
        }
    }

    for (int i = 0; i < routes.size(); i++) {
        char direction = routes[i][0];
        int move = stoi(routes[i].substr(2)); // 문자열을 숫자로 변환

        if (checkGo(direction, move, x, y)) {
            if (direction == 'W') {
                x -= move;
            } else if (direction == 'E') {
                x += move;
            } else if (direction == 'N') {
                y -= move;
            } else if (direction == 'S') {
                y += move;
            }
        }
    }
    answer.push_back(y);
    answer.push_back(x);
    return answer;
}

bool checkGo(char direction, int move, int x, int y) {
    if (move == 0) {
        return true;
    }

    if (direction == 'W' && x - 1 >= 0) {
        if (map[y][x - 1] != 1) {
            return false;
        }
        return checkGo(direction, move - 1, x - 1, y);
    } else if (direction == 'E' && x + 1 < 50) {
        if (map[y][x + 1] != 1) {
            return false;
        }
        return checkGo(direction, move - 1, x + 1, y);
    } else if (direction == 'N' && y - 1 >= 0) {
        if (map[y - 1][x] != 1) {
            return false;
        }
        return checkGo(direction, move - 1, x, y - 1);
    } else if (direction == 'S' && y + 1 < 50) {
        if (map[y + 1][x] != 1) {
            return false;
        }
        return checkGo(direction, move - 1, x, y + 1);
    }
    return false;
}
