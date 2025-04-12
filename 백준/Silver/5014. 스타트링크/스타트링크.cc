#include<iostream>
using namespace std;
int floors, cur, destination, up_count, down_count, ret,visited[1000004], cnt;
int main() {
	cin >> floors >> cur >> destination >> up_count >> down_count;
	while (cur != destination) {
		cnt++;
		if (visited[cur]) {
			cout << "use the stairs" << "\n";
			exit(0);
		}
		visited[cur] = 1;
		if (cur + up_count <= destination) {
			cur += up_count;
			continue;
		}
		if (cur - down_count > 0) {
			cur -= down_count;
			continue;
		}
		if (cur + up_count <= floors) {
			cur += up_count;
			continue;
		}
	}
	cout << cnt << "\n";
	return 0;
}