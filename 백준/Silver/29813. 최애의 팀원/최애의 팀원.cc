#include<stdio.h>
#include<queue>
#include<string>
int n, m;
char c[4];
std::string s;
std::queue<std::pair<std::string, int>> q;
int main() {
	scanf("%d", &n);
	while (n--) {
		scanf("%s %d", c, &m);
		s = c;
		q.push({ s, m });
	}
	while (q.size() != 1) {
		int num = q.front().second;
		q.pop();
		for (int i = 0; i < num - 1; i++) {
			q.push(q.front());
			q.pop();
		}
		q.pop();
	}
	printf("%s", q.front().first.c_str());
	return 0;
}