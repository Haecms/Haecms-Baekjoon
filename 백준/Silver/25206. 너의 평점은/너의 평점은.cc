#include<iostream>
#include<map>
using namespace std;
float hakjeom;
string title, score;
map<string, float>m = {
	{"A+", 4.5},{"A0", 4},{"B+", 3.5},{"B0", 3},{"C+", 2.5},{"C0", 2.0},{"D+", 1.5},{"D0", 1.0},{"F", 0}
};
int main() {
	int cnt = 0;
	double calscore = 0;
	double calhakjeom = 0;
	for (int i = 0; i < 20; i++) {
		cin >> title >> hakjeom >> score;
		if (score == "P") continue;
		calhakjeom += hakjeom;
		calscore += hakjeom * m[score];
	}
	cout.precision(7);
	if (calscore) cout << calscore / calhakjeom;
	else cout << "0";
}