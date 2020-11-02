#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("bminput.txt", "r", stdin);
	freopen("bmoutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	int t;
	cin >> t;
	while (t--) {
		int n, i;
		cin >> n >> i;
		int f = 1;  //00000001
		f = f << i; //if i=1 then 000000010
		int res = n & f;  //checks the ith pos and of bits and return 0 or 1
		if (res == 0) {
			cout << "false" << endl;
		} else {
			cout << "True" << endl;
		}
	}


	return 0;


}