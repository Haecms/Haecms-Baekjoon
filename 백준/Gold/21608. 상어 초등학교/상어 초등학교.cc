#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int n, a, b, c, d, e, ret;
int seat[21][21];
int score[5] = { 0,1,10,100,1000 };
int dy[4] = { 0,1,0,-1 };
int dx[4] = { 1,0,-1,0 };
struct A { int a, b, c, d, e; };
struct B {
	int y, x, blankCnt; 
	
	bool operator<(const B b) const {
		if (blankCnt != b.blankCnt) return blankCnt > b.blankCnt;
		if (y != b.y) return y < b.y;
		return x < b.x;
	}
};
vector<A> students;
pair<int,int> check_like_student(int y, int x, int b, int c, int d, int e) {
	int cnt = 0;
	int blankCnt = 0;
	for (int i = 0; i < 4; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny<1 || nx <1 || ny>n || nx >n) continue;

		if (!seat[ny][nx]) blankCnt++;
		else if (seat[ny][nx] == b || seat[ny][nx] == c || seat[ny][nx] == d || seat[ny][nx] == e) cnt++;
	}
	return { cnt,blankCnt };
}
int main() {
	cin >> n;
	for (int k = 0; k < n * n; k++) {
		cin >> a >> b >> c >> d >> e;
		students.push_back({ a,b,c,d,e });
	}
	for (A student : students) {
		int max_cnt = 0;
		int total_like_studentCnt = 0;
		vector<B> tempSeat;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (seat[i][j]) continue;
				pair<int, int> like_studentCnt = check_like_student(i, j, student.b, student.c, student.d, student.e);
				if (like_studentCnt.first == total_like_studentCnt) {
					tempSeat.push_back({ i,j, like_studentCnt.second });
				}
				else if (like_studentCnt.first > total_like_studentCnt) {
					total_like_studentCnt = like_studentCnt.first;
					tempSeat = vector<B>();
					tempSeat.push_back({ i,j, like_studentCnt.second });
				}
			}
		}
		sort(tempSeat.begin(), tempSeat.end());
		seat[tempSeat[0].y][tempSeat[0].x] = student.a;
	}
	for (A student : students) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (student.a == seat[i][j]) {
					pair<int, int> like_studentCnt = check_like_student(i, j, student.b, student.c, student.d, student.e);
					ret += score[like_studentCnt.first];
				}
			}
		}

	}
	cout << ret << "\n";
	return 0;
}