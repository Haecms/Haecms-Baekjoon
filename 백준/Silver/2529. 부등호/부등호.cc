#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
char a[10];
int k, visited[11];
string maxNumber = "000000000", minNumber = "999999999";

bool checkGood(int leftInput, int rightInput, char sign) {
	if (sign == '<') return leftInput < rightInput;
	else if (sign == '>') return leftInput > rightInput;
}

void dfs(int number, string value, int time) {
	visited[number] = 1;
	for (int i = 0; i < 10; i++) {
		if (visited[i]) continue;
		if (checkGood(number, i, a[time])) {
			if (time + 1 == k) {
				visited[number] = 0;
				maxNumber = max(maxNumber, value + to_string(i));
				minNumber = min(minNumber, value + to_string(i));
			}
			else {
				dfs(i, value + to_string(i), time + 1);
			}
		}
	}
	visited[number] = 0;
}
int main() {
	cin >> k;
	for (int i = 0; i < k; i++) { cin >> a[i]; }
	for (int i = 0; i < 10; i++) { dfs(i, to_string(i), 0); }	
	cout << maxNumber << "\n" << minNumber << "\n";
}
