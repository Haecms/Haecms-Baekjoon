#include <string>
#include <vector>

using namespace std;

int dp[100004];

int solution(int n, vector<int> money) {
    dp[0] = 1;
	for (int a : money) {
		for (int i = a; i <= n; i++) {
			dp[i] = (dp[i] + dp[i - a]) % 1000000007;
		}
	}
    return dp[n];
}