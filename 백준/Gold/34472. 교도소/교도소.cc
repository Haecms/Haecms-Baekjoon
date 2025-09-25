#include<iostream>
#include<math.h>
using namespace std;
typedef long long ll;
ll n, a, arr[500004], need, sum, ret, rest;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	need = sum / n;
	for (int k = 0; k < 2; k++) {
		for (int i = 0; i < n; i++) {
			ret += rest;
			if (arr[i] > need) {
				rest += (arr[i] - need);
				arr[i] = need;
			}
			else if (arr[i] < need) {
				if (arr[i] + rest >= need) {
					rest -= (need - arr[i]);
					arr[i] = need;
				}
				else {
					arr[i] += rest;
					rest = 0;
				}
			}
		}
	}
	cout << ret << "\n";
	return 0;
}