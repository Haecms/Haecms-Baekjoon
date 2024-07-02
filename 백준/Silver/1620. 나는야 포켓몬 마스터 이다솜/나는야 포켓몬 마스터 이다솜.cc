#include<bits/stdc++.h>
using namespace std;
int n, k;
string name;
map<string, int> po_nu;
map<int, string> nu_po;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> name; po_nu[name] = i; nu_po[i] = name;
	}
	for (int i = 0; i < k; i++) {
		cin >> name;
		if (name[0] >= 65 && name[0] <= 90) { cout << po_nu[name] << "\n"; }
		else { cout << nu_po[stoi(name)] << "\n"; }
	}
}