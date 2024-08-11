#include<bits/stdc++.h>
using namespace std;
int n, m, s;
map<int,int> a, ac;
vector<pair<int, int>> v;

bool cmp(pair<int, int> a, pair<int, int> b){
    if(a.first == b.first) return ac[a.second] < ac[b.second];
    return a.first > b.first;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);cout.tie(NULL);
    cin >> n >> m;
    for(int i=0; i<n; i++) {
        cin >> s; a[s]++;
        if(ac[s] == 0) ac[s] = i+1;
    }
    for(auto it : a) v.push_back({it.second, it.first});
    sort(v.begin(), v.end(), cmp);
    for(auto it : v){
        for(int i =0; i<it.first; i++){
            cout << it.second << " ";
        }
    }
}