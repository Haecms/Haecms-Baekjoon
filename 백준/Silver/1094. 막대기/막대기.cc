#include<bits/stdc++.h>
using namespace std;
int n,a,b=64,start=64;
vector<int> intArray = {64};
int main() {
	cin >> n;
	while(b != n) {
		start /= 2;
		b = 0;
		intArray.pop_back();
		for (auto c : intArray) b += c;
		intArray.push_back(start);
		if (b + start < n) {
			intArray.push_back(start);
		}
		b += start;
	}
	cout << intArray.size() << "\n";
}