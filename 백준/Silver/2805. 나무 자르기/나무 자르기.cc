#include<iostream>
using namespace std;
long long n, m, trees[1000004], maxHeight = 0, leftHeight = 0, rightHeight = 0;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> trees[i];
		rightHeight = max(trees[i], rightHeight);
	}
	maxHeight = rightHeight;
	while (true) {
		long long curTrees = 0;
		long long ifTrees = 0;
		for (int i = 0; i < n; i++) {
			if (trees[i] > maxHeight) curTrees += trees[i] - maxHeight;
			if (trees[i] > maxHeight - 1) ifTrees += trees[i] - maxHeight - 1;
		}
		if (curTrees >= m && ifTrees < m) break;
		else {
			long long addHeight = (rightHeight - maxHeight) % 2 == 0 ? (rightHeight - maxHeight) / 2 : ((rightHeight - maxHeight) / 2) + 1;
			long long minusHeight = (maxHeight - leftHeight) % 2 == 0 ? (maxHeight - leftHeight) / 2 : ((maxHeight - leftHeight) / 2) + 1;
			if (curTrees < m) {
				rightHeight = maxHeight;
				maxHeight -= minusHeight;
			}
			else {
				leftHeight = maxHeight;
				maxHeight += addHeight;
			}
		}
	}
	cout << maxHeight << "\n";
}