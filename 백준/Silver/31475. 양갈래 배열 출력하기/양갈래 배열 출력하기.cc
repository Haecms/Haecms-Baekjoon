#include<iostream>
#include<string>
using namespace std;
int n, m, visited[2004][2004];
string s;
char c;
void go_left_right(int y, int x, int count) {
	int leftx = x - 1;
	int lefty = y;
	int leftcount = count;
	int left_right_go = m / 2;
	int up_down_go = n - 1;
	int rightx = x + 1;
	int righty = y;
	int rightcount = count;
	while (leftcount < n * (m / 2 + 1)) {
		if (c == 'U') {
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[lefty][leftx--] = leftcount++;
			}
			lefty--;
			leftx++;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[lefty--][leftx] = leftcount++;
			}
			lefty++;
			leftx++;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[lefty][leftx++] = leftcount++;
			}
			lefty++;
			leftx--;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[lefty++][leftx] = leftcount++;
			}
			lefty--;
			leftx--;
			up_down_go--;
		}
		else {
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[lefty][leftx--] = leftcount++;
			}
			lefty++;
			leftx++;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[lefty++][leftx] = leftcount++;
			}
			lefty--;
			leftx++;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[lefty][leftx++] = leftcount++;
			}
			lefty--;
			leftx--;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[lefty--][leftx] = leftcount++;
			}
			lefty++;
			leftx--;
			up_down_go--;
		}

	}
	left_right_go = m / 2;
	up_down_go = n - 1;
	while (rightcount < n * (m / 2 + 1)) {
		if (c == 'U') {
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[righty][rightx++] = rightcount++;
			}
			righty--;
			rightx--;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[righty--][rightx] = rightcount++;
			}
			righty++;
			rightx--;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[righty][rightx--] = rightcount++;
			}
			righty++;
			rightx++;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[righty++][rightx] = rightcount++;
			}
			righty--;
			rightx++;
			up_down_go--;
		}
		else {
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[righty][rightx++] = rightcount++;
			}
			righty++;
			rightx--;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[righty++][rightx] = rightcount++;
			}
			righty--;
			rightx--;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[righty][rightx--] = rightcount++;
			}
			righty--;
			rightx++;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[righty--][rightx] = rightcount++;
			}
			righty++;
			rightx++;
			up_down_go--;
		}
		
	}
}
void go_up_down(int y, int x, int count) {
	int upx = x;
	int upy = y - 1;
	int upcount = count;
	int left_right_go = m - 1;
	int up_down_go = n / 2;
	int downx = x;
	int downy = y + 1;
	int downcount = count;
	while (upcount < (n / 2 + 1) * m) {
		if (c == 'L') {
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[upy--][upx] = upcount++;
			}
			upy++;
			upx--;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[upy][upx--] = upcount++;
			}
			upy++;
			upx++;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[upy++][upx] = upcount++;
			}
			upy--;
			upx++;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[upy][upx++] = upcount++;
			}
			upy--;
			upx--;
			left_right_go--;
		}
		else {
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[upy--][upx] = upcount++;
			}
			upy++;
			upx++;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[upy][upx++] = upcount++;
			}
			upy++;
			upx--;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[upy++][upx] = upcount++;
			}
			upy--;
			upx--;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[upy][upx--] = upcount++;
			}
			upy--;
			upx++;
			left_right_go--;
		}
		
	}
	left_right_go = m - 1;
	up_down_go = n / 2;
	while (downcount < n * (m / 2 + 1)) {
		if (c == 'L') {
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[downy++][downx] = downcount++;
			}
			downy--;
			downx--;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[downy][downx--] = downcount++;
			}
			downy--;
			downx++;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[downy--][downx] = downcount++;
			}
			downy++;
			downx++;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[downy][downx++] = downcount++;
			}
			downy++;
			downx--;
			left_right_go--;
		}
		else {
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[downy++][downx] = downcount++;
			}
			downy--;
			downx++;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[downy][downx++] = downcount++;
			}
			downy--;
			downx--;
			left_right_go--;
			if (!up_down_go) break;
			for (int i = 0; i < up_down_go; i++) {
				visited[downy--][downx] = downcount++;
			}
			downy++;
			downx--;
			up_down_go--;
			if (!left_right_go) break;
			for (int i = 0; i < left_right_go; i++) {
				visited[downy][downx--] = downcount++;
			}
			downy++;
			downx++;
			left_right_go--;
		}
		
	}
}
void setOneline(int y, int x, int count, char gubun)
{
	if (gubun == 'U') {
		while (y < n) {
			visited[y++][x] = count++;
		}
		y--;
	}
	else if (gubun == 'D') {
		while (y >= 0) {
			visited[y--][x] = count++;
		}
		y++;
	}
	else if (gubun == 'L') {
		while (x < m) {
			visited[y][x++] = count++;
		}
		x--;
	}
	else if (gubun == 'R') {
		while (x >= 0) {
			visited[y][x--] = count++;
		}
		x++;
	}
	if (gubun == 'D' || gubun == 'U') go_left_right(y, x, count);
	else if (gubun == 'R' || gubun=='L') go_up_down(y, x, count);
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n >> m >> c;

	if (c == 'U') setOneline(0, m / 2, 1, 'U');
	else if (c == 'D') setOneline(n - 1, m / 2, 1, 'D');
	else if (c == 'L') setOneline(n / 2, 0, 1, 'L');
	else if (c == 'R') setOneline(n / 2, m - 1, 1, 'R');
	int cnt = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			s += (to_string(visited[i][j])) + ' ';
		}
		s += '\n';
	}
	cout << s << "\n";
}