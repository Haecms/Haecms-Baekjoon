#include<iostream>
#include<vector>
using namespace std;
vector<int> v;
vector<vector<int>> party(54);       // 파티에 어느 인간이 있는지
vector<vector<int>> human_party(54); // 인간이 어느 파티에 갔는지
int personSize, partyCnt, personCnt, participantCnt, smartPerson[51], participant, va, cnt;

void go(int smartH) {
	for (int a : human_party[smartH]) {
		for (int b : party[a]) {
			if (smartPerson[b]) continue;
			smartPerson[b] = 1;
			go(b);
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> personSize >> partyCnt >> personCnt;
	for (int i = 0; i < personCnt; i++) {
		cin >> va;
		smartPerson[va] = 1;
		v.push_back(va);
	}
	for (int i = 0; i < partyCnt; i++) {
		cin >> participantCnt;
		while (participantCnt--) {
			cin >> participant;
			party[i].push_back(participant);
			human_party[participant].push_back(i);
		}
	}

	for (int i = 0; i < v.size(); i++) go(v[i]);
	
	for (int i = 0; i < partyCnt; i++) {
		if (!smartPerson[party[i][0]]) cnt++;
	}
	cout << cnt << "\n";
}