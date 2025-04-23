#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

bool cmp1(pair<int, int> a, pair<int, int> b) {
	return a.second > b.second;
}
bool cmp2(pair<string, int> a, pair<string, int> b) {
	return a.second > b.second;
}

vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string, int> ma;
    map<string, vector<pair<int,int>>> ma2;
    
    for (int i = 0; i < genres.size(); i++) {
		ma[genres[i]] += plays[i];
		ma2[genres[i]].push_back({ i, plays[i] });
        
		sort(ma2[genres[i]].begin(), ma2[genres[i]].end(), cmp1);
        
		if (ma2[genres[i]].size() > 2) ma2[genres[i]].pop_back();
	}
    
	vector<pair<string, int>> v_genres(ma.begin(), ma.end());
	sort(v_genres.begin(), v_genres.end(), cmp2);
    
	for (pair<string, int> p : v_genres) {
		for (int i = 0; i < ma2[p.first].size(); i++) {
			answer.push_back(ma2[p.first][i].first);
		}
	}
    
    return answer;
}