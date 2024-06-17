#include<bits/stdc++.h>
using namespace std;

void hello(vector<int> a) {
	for (int i = 0; i <= a.size() - 7; i++) {
		for (int j = i + 1; j <= a.size() - 6; j++) {
			for (int k = j + 1; k <= a.size() - 5; k++) {
				for (int l = k + 1; l <= a.size() - 4; l++) {
					for (int m = l + 1; m <= a.size() - 3; m++) {
						for (int n = m + 1; n <= a.size() - 2; n++) {
							for (int o = n + 1; o <= a.size() - 1; o++) {
								if (a[i] + a[j] + a[k] + a[l] + a[m] + a[n] + a[o] == 100) {
									vector<int> answer = { a[i], a[j],a[k],a[l],a[m],a[n],a[o] };
									sort(answer.begin(), answer.end());
									cout << answer[0] << endl;
									cout << answer[1] << endl;
									cout << answer[2] << endl;
									cout << answer[3] << endl;
									cout << answer[4] << endl;
									cout << answer[5] << endl;
									cout << answer[6] << endl;
									return;
								}
							}
						}
					}
				}
			}
		}
	}
}
int main() {
	vector<int> a;
	int value;
	for (int i = 0; i < 9; i++) {
		cin >> value;
		a.push_back(value);
	}
	hello(a);
}