#include<stdio.h>
#include<algorithm>
int main() {
	int a,b,c;
	while(1) {
		scanf("%d%d%d", &a,&b,&c);
		int B = std::max(std::max(a, b), c);
		if (!a && !b && !c) break;
		else if (B >= a + b + c - B) printf("Invalid\n");
		else if (a == b && a == c) printf("Equilateral\n");
		else if (a == b || a == c || b == c) printf("Isosceles\n");
		else printf("Scalene\n");
	}
}