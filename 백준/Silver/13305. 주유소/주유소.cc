#include<iostream>
#include<vector>
using namespace std;
long long n, a, prevMin = 10000000000, totaldis, prevVal;
vector<long long> dis, oil;
int main() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		cin >> a;
		dis.push_back(a);
		totaldis += a;
	}
	for (int i = 0; i < n; i++) cin >> a, oil.push_back(a);
	for (int i = 0; i < n-1; i++) {
		if (oil[i] < prevMin) {
			if (prevMin != 10000000000) prevVal = prevVal - (prevMin * totaldis) + oil[i] * totaldis;
			else prevVal = oil[i] * totaldis;
			prevMin = oil[i];
		}
		totaldis -= dis[i];
	}
	cout << prevVal << "\n";
	return 0;
}