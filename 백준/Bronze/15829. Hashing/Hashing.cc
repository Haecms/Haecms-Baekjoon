#include<iostream>
using namespace std;
int n;
long long ret;
string s;
int main() {
	cin >> n >> s;
	for (int i = 0; i < n; i++) {
		long long temp = 1;
		for (int j = 0; j < i; j++) {
			temp = temp * 31 % 1234567891;
		}
		ret += (s[i] - 96) * temp ;
	}
	cout << ret % 1234567891 << "\n";
	return 0;
}