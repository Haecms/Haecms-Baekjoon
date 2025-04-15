#include<iostream>
#include<vector>
using namespace std;
int n, visited[100];
char a, b, c;
vector<int> v[100];

void go_hoowi(int idx) {
	for (int d : v[idx]) {
		if (d > 60) {
			go_hoowi(d);
			cout << char(d);
		}
	}
}
void go_joongwi(int idx) {
	for (int d : v[idx]) {
		go_joongwi(d);
		if (!visited[idx]) {
			cout << char(idx);
			visited[idx] = 1;
		}
	}
}

void go_jeonwi(int idx) {
	cout << char(idx);
	for (int d : v[idx]) {
		if(d > 60) go_jeonwi(d);
	}
}
int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a >> b >> c;
		v[a].push_back(b);
		v[a].push_back(c);
	}
	go_jeonwi('A'); cout << "\n";
	go_joongwi('A'); cout << "\n";
	go_hoowi('A'); cout << "A\n";
	return 0;
}