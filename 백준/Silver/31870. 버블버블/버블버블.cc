#include<iostream>
using namespace std;
int a1[1001], a2[1002], n, count1=0, count2=0, temp;
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
		a2[i] = a1[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a1[i] > a1[j]) {
				count1++;
				temp = a1[i];
				a1[i] = a1[j];
				a1[j] = temp;
			}
			if (a2[i] < a2[j]) {
				count2++;
				temp = a2[i];
				a2[i] = a2[j];
				a2[j] = temp;
			}
		}
	}
	cout << min(count1, count2 + 1) << "\n";
	return 0;
}