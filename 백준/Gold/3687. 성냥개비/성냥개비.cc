#include<iostream>
#include<vector>
#include<string>
using namespace std;
int n, a, b[6] = { 1,7,4,2,0,8 };
string dp[101];

string sCheck(string s1, string s2) {
	if (s1 == "") return s2;
	int s1Size = s1.size();
	int s2Size = s2.size();
	if (s1Size != s2Size) {
		int minSize = min(s1Size, s2Size);
		return minSize == s1Size ? s1 : s2;
	}
	return s1 > s2 ? s2 : s1;
}
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	for (int i = 0; i < 101; i++) dp[i] = "99999999999999999999999999999999999999999999999999";
	dp[2] = "1";
	dp[3] = "7";
	dp[4] = "4";
	dp[5] = "2";
	dp[6] = "6";
	dp[7] = "8";
	for (int i = 8; i < 101; i++) {
		for (int j = 0; j < 6; j++) {
			dp[i] = sCheck(dp[i], dp[i - j -2] + to_string(b[j]));
		}
	}
	
	while (n--) {
		cin >> a;
		cout << dp[a] << " ";
		int temp = a;
		string s = "";
		while (temp) {
			if (temp == 3) { s = "7" + s; temp -= 3; }
			else { s = "1" + s; temp -= 2; }
		}
		cout << s << "\n";
	}
    return 0;
}