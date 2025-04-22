#include<iostream>
#include<algorithm>
using namespace std;
int n, a,b,c, ba,bb,bc,sa,sb,sc;
int main() {
	ios_base::sync_with_stdio(0); cin.tie(0); cout.tie(0);
	cin >> n;
	while(n--) {
		cin >> a >> b >> c;

		int ba_c = max(ba + a, bb + a);
		int bb_c = max(ba + b, max(bb + b, bc + b));
		int bc_c = max(bb + c, bc + c);
		
		int sa_c = min(sa + a, sb + a);
		int sb_c = min(sa + b, min(sb + b, sc + b));
		int sc_c = min(sb + c, sc + c);

		ba = ba_c; bb = bb_c; bc = bc_c;
		sa = sa_c; sb = sb_c; sc = sc_c;
	}
	cout << max(ba, max(bb, bc)) << " ";
	cout << min(sa, min(sb, sc)) << " ";
}