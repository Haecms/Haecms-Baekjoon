#include <string>
#include <vector>
#include <unordered_map>

using namespace std;

    long long solution(long long n) {
    long long answer = 0;
    unordered_map<int, int> hello;
    while (n > 0) {
    	hello[n % 10]++;
    	n /= 10;
    }
    
    for (int i = 9; i >= 0; i--) {
    	for (int j = 0; j < hello[i]; j++) {
    		answer *= 10;
    		answer += i;
    	}
    }
    return answer;
}