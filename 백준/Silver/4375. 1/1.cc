#include <iostream>
using namespace std;
int a;
int main()
{
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	while (scanf("%d", &a) != EOF) {
		int c=1, m = 0;
		while (m = (m*10+1)%a ) c++;
		cout << c << '\n';
	}
}