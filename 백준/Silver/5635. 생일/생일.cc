#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;
int n,d,m,y;
string s;
struct A {
	string name;
	int day;
	int month;
	int year;

	bool operator<(const A& x) const {
		if (year != x.year) return year < x.year;
		if (month != x.month) return month < x.month;
		return day < x.day;
	}
};
vector<A> v;
int main() {
	cin >> n;
	while (n--) {
		cin >> s >> d >> m >> y;
		v.push_back({ s, d, m, y });
	}
	sort(v.begin(), v.end());
	cout << v[v.size()-1].name << "\n";
	cout << v[0].name << "\n";
}