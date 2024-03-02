#include <string>
#include <vector>

using namespace std;

int solution(string t, string p) {
    long answer = 0;
    
    for (long i = 0; i < t.size() - p.size() +1; i++) {
	    long a = atol(t.substr(i, p.size()).c_str());
	    if (a <= atol(p.c_str())) {
		    answer++;
	    }
    }
    return answer;
}