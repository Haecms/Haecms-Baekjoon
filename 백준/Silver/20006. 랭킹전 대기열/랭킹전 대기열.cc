#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
using namespace std;
int n, m, lv;
string name;
vector<pair<int, vector<pair<int, string>>>> v;
bool cmp(pair<int,string> a, pair<int, string> b) {
	return a.second < b.second;
}
int main() {
	scanf("%d %d", &n, &m);
	for (int i = 0; i < n; i++) {
		char cn[20];
		scanf("%d %s", &lv, cn);
		name = cn;
		for (vector<pair<int, vector<pair<int, string>>>>::iterator it = v.begin(); ; it++) {
			if (it == v.end()) { v.push_back({ lv, {{ lv,name }} }); break; }
			if (lv >= it->first - 10 && lv <= it->first + 10 && it->second.size() != m) {
				it->second.push_back({ lv,name }); break;
			}
		}
	}
	for (auto &a : v) sort(a.second.begin(), a.second.end(), cmp);
	for (auto a : v) {
		if (a.second.size() == m) printf("Started!\n");
		else printf("Waiting!\n");
		for (auto b : a.second) printf("%d %s\n", b.first, b.second.c_str());
	}
	return 0;
}