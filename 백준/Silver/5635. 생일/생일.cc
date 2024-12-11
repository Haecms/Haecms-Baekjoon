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
};
vector<A> v;
bool cmp(A a, A b) {
	if (a.year == b.year) {
		if (a.month == b.month)  return a.day > b.day; 
		else return a.month > b.month;
	}
	else return a.year > b.year;
}
int main() {
	cin >> n;
	while (n--) {
		cin >> s >> d >> m >> y;
		v.push_back({ s, d, m, y });
	}
	sort(v.begin(), v.end(), cmp);
	cout << v[0].name << "\n";
	cout << v[v.size()-1].name << "\n";
}