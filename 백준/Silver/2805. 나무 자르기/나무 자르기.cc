#include<iostream>
#include<map>
using namespace std;
long long n, m, a, maxCutHeight=0;
map<int, int> trees_ex;
int main() {
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> a;
		trees_ex[a]++;
	}
	int lowHeight = 0;
	int highHeight = 2000000000;
	
	while (lowHeight <= highHeight) {
		long long curTrees = 0;
		long long cutHeight = (highHeight + lowHeight) / 2;
		for (auto b : trees_ex) {
			if (b.first > cutHeight) curTrees += (b.first - cutHeight) * b.second;
		}
		if (curTrees >= m) {
			maxCutHeight = cutHeight;
			lowHeight = cutHeight + 1;
		}
		else  highHeight = cutHeight -1;
	}
	cout << maxCutHeight << "\n";
}