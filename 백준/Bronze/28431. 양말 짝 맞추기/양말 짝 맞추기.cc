#include<stdio.h>
int n, xr=0;
int main() {
	for(int i=0; i<5; i++) {
        scanf("%d", &n);
        xr ^= n;
    }
    printf("%d", xr);
}