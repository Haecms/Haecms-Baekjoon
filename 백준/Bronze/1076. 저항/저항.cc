#include<iostream>
#include<string>
#include<map>
#include<vector>
using namespace std;
string s, res="";
map<string, vector<pair<string, int>>> m = {
    {"black", {{"0", 1}}},
    {"brown", {{"1", 10}}},
    {"red", {{"2", 100}}},
    {"orange", {{"3", 1000}}},
    {"yellow", {{"4", 10000}}},
    {"green", {{"5", 100000}}},
    {"blue", {{"6", 1000000}}},
    {"violet", {{"7", 10000000}}},
    {"grey", {{"8", 100000000}}},
    {"white", {{"9", 1000000000}}}
};
int main() {	
	int c = 2;
	while (c--) {
		cin >> s;
        res += m[s].front().first;
	}
    cin >> s;
    res = to_string(stoi(res) * (long long)m[s].front().second);
    cout << res;

}
