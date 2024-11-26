#include<iostream>
#include<vector>
using namespace std;
int n, teacher, cnt=0;
string arriveTime, job;
vector<int> student;
int main() {
	cin >> n;
	for (int i = 0; i <= n; i++) {
		cin >> arriveTime >> job;
		if (job == "student") {
			student.push_back(((arriveTime[0] - '0') * 1000) + ((arriveTime[1] - '0') * 100) + ((arriveTime[3] - '0') * 10) + (arriveTime[4] - '0'));
		}
		else {
			teacher = ((arriveTime[0] - '0') * 1000) + ((arriveTime[1] - '0') * 100) + ((arriveTime[3] - '0') * 10) + (arriveTime[4] - '0');
		}
	}
	cin >> arriveTime;
	if (((arriveTime[0] - '0') * 1000) + ((arriveTime[1] - '0') * 100) + ((arriveTime[3] - '0') * 10) + (arriveTime[4] - '0') > teacher){
		teacher = ((arriveTime[0] - '0') * 1000) + ((arriveTime[1] - '0') * 100) + ((arriveTime[3] - '0') * 10) + (arriveTime[4] - '0');
	}
	for (int a : student) {
		if (teacher <= a) cnt++;
	}
	cout << cnt << "\n";
}