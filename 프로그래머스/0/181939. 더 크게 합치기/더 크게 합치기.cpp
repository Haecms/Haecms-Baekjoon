#include <string>
#include <vector>

using namespace std;

int solution(int a, int b) {
    std::string c = std::to_string(a);
    std::string d = std::to_string(b);

    int answer = c + d > d + c ? std::stoi(c + d) : std::stoi(d + c);
    return answer;
}