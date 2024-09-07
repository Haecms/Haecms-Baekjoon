#include<stdio.h>
int A[3][3];
bool check() {
	for (int i = 0; i < 3; i++) {
		if (A[0][i] && (A[0][i] == A[1][i] && A[0][i] == A[2][i])) return true;
		if (A[i][0] && (A[i][0] == A[i][1] && A[i][0] == A[i][2])) return true;
	}
	if (A[0][0] && (A[0][0] == A[1][1] && A[0][0] == A[2][2])) return true;
	if (A[0][2] && (A[0][2] == A[1][1] && A[0][2] == A[2][0])) return true;
	return false;
}
int main() 	{
	int person, y, x, round=9;
	bool flag = false;
	scanf("%d", &person);
	while (round--) {
		scanf("%d%d", &y, &x);
		A[y-1][x-1] = person;
		if (flag = check()) break;
		person = person == 1 ? 2 : 1;
	}
	if (flag) printf("%d", person);
	else printf("0");
	return 0;
}
