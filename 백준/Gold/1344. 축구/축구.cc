#include<iostream>
#include<memory.h>
#include<math.h>
using namespace std;
double n, m, dp[20][20][20];
int prime[20];

double go(int a, int b, int cnt) {
	if (cnt == 18) {
		if (!prime[a] || !prime[b]) return 1.0;
		else return 0.0;
	}
	double& ret = dp[a][b][cnt];
	if (ret > -0.5) return ret;
	ret = 0.0;
	ret += go(a, b, cnt + 1) * (1 - n) * (1 - m);
	ret += go(a+1, b, cnt + 1) * n * (1 - m);
	ret += go(a, b+1, cnt + 1) * (1 - n) * m;
	ret += go(a+1, b+1, cnt + 1) * n*m;
	return ret;
}

int main() {
	cin >> n >> m;
	n /= 100; m /= 100;
	fill(&dp[0][0][0], &dp[0][0][0] + 20 * 20 * 20, -1);
	prime[0] = 1; prime[1] = 1;
	for (int i = 2; i < 20; i++) {
		for (int j = 2; j <= sqrt(i); j++) {
			if (i % j == 0) {
				prime[i] = 1;
				break;
			}
		}
		for (int j = i * i; j < 20; j += i) prime[j] = 1;
	}
	cout.fixed;
	cout.precision(10);
	cout << go(0,0,0) << "\n";
	return 0;
}