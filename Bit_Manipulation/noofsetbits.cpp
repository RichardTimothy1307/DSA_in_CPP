#include<bits/stdc++.h>
using namespace std;

int main() {
#ifndef ONLINE_JUDGE
	freopen("bminput.txt", "r", stdin);
	freopen("bmoutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	int q;
	cin >> q;
	while (q--) {

		int n;
		cin >> n;
		int c = n;
		int count = 0;
		while (n != 0) {

			if (n & 1 != 0) {
				count++;
			} else {
				//
			}
			n = n >> 1;

		}
		cout << "logn time complexity because right shit n/2^i" << endl;
		cout << count << endl;
		cout << "With __builtin_popcount()" << endl;
		cout << __builtin_popcount(c) << endl;

		//Another approach n&n-1 which reduces set bit everytime that is
		//makes the rightmost or last set bit to 0

		int cnt = 0;
		while (c != 0) {
			cnt++;
			c = c & (c - 1);
		}
		cout << cnt << endl;




	}










	return 0;
}