#include <string>
#include <vector>
#include<unordered_map>
using namespace std;

long long solution(vector<int> weights) {
    long long answer = 0;
    unordered_map<double, long long> dict;

    for (auto weight : weights) {
        dict[weight] += 1;
    }

    for (auto weight : weights) {
        dict[weight] -= 1;
        if (dict[weight] > 0) {
            answer += dict[weight];
        }
        if (dict[weight * 2] > 0) {
            answer += dict[weight * 2];
        }
        if (dict[weight / 2.0] > 0) {
            answer += dict[weight / 2.0];
        }
        if (dict[weight / 2.0 * 3] > 0) {
            answer += dict[weight / 2.0 * 3];
        }
        if (dict[weight / 3.0 * 4] > 0) {
            answer += dict[weight / 3.0 * 4];
        }
        if (dict[weight / 4.0 * 3] > 0) {
            answer += dict[weight / 4.0 * 3];
        }
        if (dict[weight / 3.0 * 2] > 0) {
            answer += dict[weight / 3.0 * 2];
        }
    }
    return answer;
}