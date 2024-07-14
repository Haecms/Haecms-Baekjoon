#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
	while (scanf("%d", &a) != EOF) {
        ll b = 0, c = 0;
		do {
			b = (b%a * 10%a) + 1%a;
			c++;
		} while (b % a);
		cout << c << "\n";
	}
}