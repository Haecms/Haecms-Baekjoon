#include<iostream>
using namespace std;
typedef long long ll;
ll n, a, arr[500004], need, sum, ret,rest;
int main() {
    ios_base::sync_with_stdio(0); cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
		sum += arr[i];
	}
	need = sum / n;
	ll overSum = 0;
	ll startIdx = 0;
	for (int i = n - 1, j=1; i >= 0; i--,j++) {
		overSum += arr[i];
		if (overSum > j * need) {
			startIdx = i;
			break;
		}
	}
	for (int i = startIdx; i < n; i++) {
		ret += rest;
		if (arr[i] > need) {
			rest += arr[i] - need;
			arr[i] = need;
		}
		else if(arr[i] < need){
			rest -= (need - arr[i]);
			arr[i] = need;
		}
	}
	arr[0] += rest;
	ret += rest;
	rest = 0;
	for (int i = 0; i < n; i++) {
		ret += rest;
		if (arr[i] > need) {
			rest += arr[i] - need;
			arr[i] = need;
		}
		else if(arr[i] < need){
			rest -= (need - arr[i]);
			arr[i] = need;
		}
	}
	cout << ret << "\n";
	return 0;
}