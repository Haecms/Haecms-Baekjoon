#include<bits/stdc++.h>
using namespace std;
int n, a[11];
int main() {
	for (int i = 0; i < 5; i++) { cin >> n; a[n]++; }
	for (int i = 0; i < 11; i++) { if (a[i] % 2 == 1) cout << i << "\n"; }
}