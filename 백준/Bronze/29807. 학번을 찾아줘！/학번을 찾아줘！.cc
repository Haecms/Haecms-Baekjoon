#include<iostream>
using namespace std;
long long n, m[5], ret=0;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> m[i];
	}
	if (m[0] > m[2]) ret += (m[0] - m[2]) * 508;
	else ret += (m[2] - m[0]) * 108;
	if(m[1] > m[3]) ret += (m[1] - m[3]) * 212;
	else ret += (m[3] - m[1]) * 305;
	if (m[4]) ret += m[4] * 707;
	ret *= 4763;
	cout << ret << "\n";
}