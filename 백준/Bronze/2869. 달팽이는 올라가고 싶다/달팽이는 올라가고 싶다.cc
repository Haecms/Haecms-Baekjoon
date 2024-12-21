#include<iostream>
using namespace std;
int n, m, a;
int main() {
	cin >> n >> m >> a;
	int d = n - m;
	int destination = a - n;
	destination % d ? cout << destination / d + 2 : cout << destination / d + 1;
}