#include<iostream>
#include<vector>
using namespace std;
int n, t, x, y, down[10][4], mright[4][10], cnt=0;
vector<int> removeDownIndex, removeRightIndex;

void moveDown(int gubun, int y, int x) {
	if (gubun == 1) {
		if (y + 1 < 10 && !down[y + 1][x]) moveDown(gubun, y + 1, x);
		else down[y][x] = 1;
	}
	else if (gubun == 2) {
		if (y + 1 < 10 && !down[y + 1][x]) moveDown(gubun, y + 1, x);
		else {
			down[y][x] = 1;
			down[y - 1][x] = 1;
		}
	}
	else {
		if(y + 1 < 10 && !down[y + 1][x] && !down[y+1][x+1]) moveDown(gubun, y + 1, x);
		else {
			down[y][x] = 1;
			down[y][x + 1] = 1;
		}
	}
}
void moveRight(int gubun, int y, int x) {
	if (gubun == 1) {
		if (x + 1 < 10 && !mright[y][x+1]) moveRight(gubun, y, x+1);
		else mright[y][x] = 1;
	}
	else if (gubun == 2) {
		if (x + 1 < 10 && !mright[y + 1][x+1] && !mright[y][x+1]) moveRight(gubun, y, x+1);
		else {
			mright[y][x] = 1;
			mright[y+1][x] = 1;
		}
	}
	else {
		if (x + 1 < 10 && !mright[y][x+1]) moveRight(gubun, y, x+1);
		else {
			mright[y][x] = 1;
			mright[y][x -1] = 1;
		}
	}
}
void checkDownData() {
	for (int i = 9; i > 5; i--) {
		int goodCnt = 0;
		for (int j = 0; j < 4; j++) {
			if (down[i][j]) goodCnt++;
		}
		if (goodCnt == 4) {
			removeDownIndex.push_back(i);
			cnt++;
		}
	}
}
void checkRightData() {
	for (int i = 9; i > 5; i--) {
		int goodCnt = 0;
		for (int j = 0; j < 4; j++) {
			if (mright[j][i]) goodCnt++;
		}
		if (goodCnt == 4) {
			removeRightIndex.push_back(i);
			cnt++;
		}
	}
}
void removeDown() {
	int vectorSize = removeDownIndex.size();
	for (int index : removeDownIndex) {
		int count = 0;
		for (int i = 0; i < 4; i++) {
			down[index][i] = 0;
		}
	}
	while (vectorSize--) {
		bool go_continue = false;
		for (int i = 9; i > 3; i--) {
			int count = 0;
			for (int j = 0; j < 4; j++) {
				if (!down[i][j]) count++;
			}
			if (count == 4) {
				go_continue = true;
			}
			if (go_continue) {
				for (int j = 0; j < 4; j++) {
					down[i][j] = down[i - 1][j];
				}
			}
		}
	}
	removeDownIndex = vector<int>();
}
void removeRight() {
	int vectorSize = removeRightIndex.size();
	for (int index : removeRightIndex) {
		for (int i = 0; i < 4; i++) {
			mright[i][index] = 0;
		}
	}
	while (vectorSize--) {
		bool go_continue = false;
		for (int i = 9; i > 3; i--) {
			int count = 0;
			for (int j = 0; j < 4; j++) {
				if (!mright[j][i]) count++;
			}
			if (count == 4) {
				go_continue = true;
			}
			if (go_continue) {
				for (int j = 0; j < 4; j++) {
					mright[j][i] = mright[j][i - 1];
				}
			}
		}
	}
	removeRightIndex = vector<int>();
}
void checkDownBanData() {
	int totalCnt = 0;
	for (int i = 4; i < 6; i++) {
		int count = 0;
		for (int j = 0; j < 4; j++) {
			if (down[i][j]) count++;
		}
		if (count) totalCnt++;
	}
	if (totalCnt == 1) {
		removeDownIndex.push_back(9);
	}
	else if (totalCnt == 2) {
		removeDownIndex.push_back(9);
		removeDownIndex.push_back(8);
	}
}
void checkRightBanData() {
	int totalCnt = 0;
	for (int i = 4; i < 6; i++) {
		int count = 0;
		for (int j = 0; j < 4; j++) {
			if (mright[j][i]) count++;
		}
		if (count) totalCnt++;
	}
	if (totalCnt == 1) {
		removeRightIndex.push_back(9);
	}
	else if (totalCnt == 2) {
		removeRightIndex.push_back(9);
		removeRightIndex.push_back(8);
	}
}
int getBlock() {
	int count = 0;
	for (int i = 6; i < 10; i++) {
		for (int j = 0; j < 4; j++) {
			if (mright[j][i]) count++;
			if (down[i][j]) count++;
		}
	}
	return count;
}
int main() {
	cin >> n;
	while (n--) {
		cin >> t >> x >> y;
		// 아래쪽 이동 로직
		moveDown(t, y, x);
		// 오른쪽 이동 로직
		moveRight(t, y, x);
		// 아래쪽 데이터 있는지 확인 로직
		checkDownData();
		// 오른쪽 데이터 있는지 확인 로직
		checkRightData();
		// 아래쪽 데이터 있으면 그 줄 만큼 지우고 위에 있는 데이터 내리기
		if (removeDownIndex.size()) { removeDown(); }
		// 오른쪽 데이터 있으면 그 줄 만큼 지우고 위에 있는 데이터 내리기
		if (removeRightIndex.size()) { removeRight(); }
		// 아래쪽의 금단의 선에 데이터가 있으면 그 줄 만큼 아래쪽 줄 지우고 데이터 옮기기
		checkDownBanData();
		removeDown();
		// 오른쪽의 금단의 선에 데이터가 있으면 그 줄 만큼 오른쪽 줄 지우고 데이터 옮기기
		checkRightBanData();
		removeRight();
	}
	int block = getBlock();
	std::cout << cnt << "\n";
	std::cout << block << "\n";
}