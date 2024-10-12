#include<iostream>
#include<algorithm>
using namespace std;
long long n, m, trees[1000004], cutHeight, maxCutHeight=0;
int main() {
	cin >> n >> m;
	for(int i=0; i<n; i++) cin >> trees[i];
	
	sort(trees, trees + n);
	long long lowHeight = 0;
	long long highHeight = trees[n - 1];
	
	while (lowHeight <= highHeight) {
		long long curTrees = 0;
		cutHeight = (highHeight + lowHeight) / 2;
		for (int i = 0; i < n; i++) {
			if (trees[i] > cutHeight) curTrees += trees[i] - cutHeight;
		}
		if (curTrees >= m) {
			maxCutHeight = cutHeight;
			lowHeight = cutHeight + 1;
		}
		else  highHeight = cutHeight -1;
	}
	cout << maxCutHeight << "\n";
}