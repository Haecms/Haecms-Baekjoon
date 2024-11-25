#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;
int n, mp, mf, ms, mv, p, f, s, v, c, ret = 987654321, visited[16], temp[16];
struct A {
	int 단백질;
	int 지방;
	int 탄수화물;
	int 비타민;
	int 가격;
};
map<int, A> m;
map<int, vector<vector<int>>> ret_v;

void go(int start, int cnt) {
	for (int i = start; i <= n; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			temp[cnt] = i;
			int danbaekjil = 0;
			int jibang = 0;
			int tansuhwamul = 0;
			int vitamin = 0;
			int price = 0;
			for (int j = 1; j <= cnt; j++) {
				danbaekjil += m[temp[j]].단백질;
				jibang += m[temp[j]].지방;
				tansuhwamul += m[temp[j]].탄수화물;
				vitamin += m[temp[j]].비타민;
				price += m[temp[j]].가격;
			}
			if (danbaekjil >= mp && jibang >= mf && tansuhwamul >= ms && vitamin >= mv) {
				if (ret >= price) {
					ret = price;
					vector<int> v;
					for (int j = 1; j <= cnt; j++) {
						v.push_back(temp[j]);
					}
					ret_v[ret].push_back(v);
				}
			}
			go(temp[cnt], cnt + 1);
			visited[i] = 0;
		}
	}
}

int main() {
	cin >> n >> mp >> mf >> ms >> mv;
	for (int i = 1; i <= n; i++) {
		cin >> p >> f >> s >> v >> c;
		m[i] = { p, f,s,v,c };
	}
	go(1, 1);
	if (ret == 987654321) {
		cout << -1 << "\n";
	}
	else {
		cout << ret << "\n";
		sort(ret_v[ret].begin(), ret_v[ret].end());
		for (int a : ret_v[ret][0]) {
			cout << a << " ";
		}
	}
}