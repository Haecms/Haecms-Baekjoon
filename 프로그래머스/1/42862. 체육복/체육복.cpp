#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    vector<int> cloth(n, 1);

    for (int i = 0; i < lost.size(); ++i) {
        cloth[lost[i] - 1] -= 1;
    }

    for (int i = 0; i < reserve.size(); ++i) {
        cloth[reserve[i] - 1] += 1;
    }

    for (int i = 0; i < cloth.size(); ++i) {
        if (i != 0 && cloth[i] == 2 && cloth[i - 1] == 0) {
            cloth[i] = 1;
            cloth[i - 1] = 1;
        } else if (i != cloth.size() - 1 && cloth[i] == 2 && cloth[i + 1] == 0) {
            cloth[i] = 1;
            cloth[i + 1] = 1;
        }
    }

    for (int student : cloth) {
        if (student != 0) {
            answer++;
        }
    }

    return answer;
}