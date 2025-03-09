#include<stdio.h>
using namespace std;
int main() {
	char c[104];
	scanf("%s", c);
	for (int i = 0; c[i] != 0; i++) {
		if (c[i] >= 97) printf("%c", c[i]-32);
		else printf("%c", c[i] + 32);
	}
	return 0;
}