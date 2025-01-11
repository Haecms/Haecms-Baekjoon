#include<iostream>
#include<queue>
using namespace std;
int a,b,c,d;
priority_queue<int, vector<int>, greater<>> pq;
int main() {
	cin >> a >> b >> c >> d;
	pq.push(abs(0 - a));
	pq.push(abs(a - c));
	pq.push(abs(0 - b));
	pq.push(abs(b - d));
	cout << pq.top() << "\n";
	return 0;
}