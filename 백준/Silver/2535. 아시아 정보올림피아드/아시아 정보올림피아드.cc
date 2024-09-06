#include<stdio.h>
#include<vector>
#include<algorithm>
using namespace std;
int N, c, h, s, arr[101],cnt=0;
vector<pair<int, pair<int, int>>> v;
bool sorthello(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b) {
	return a.first > b.first;
}
int main() 	{
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		scanf("%d%d%d", &c, &h, &s);
		v.push_back({ s, { c,h } });
	}
	sort(v.begin(), v.end(), sorthello);
	for (auto z : v) {
		if (arr[z.second.first] != 2) {
			arr[z.second.first]++; cnt++;
			printf("%d %d\n", z.second.first, z.second.second);
			if (cnt == 3) break;
		}
	}

	return 0;
}
