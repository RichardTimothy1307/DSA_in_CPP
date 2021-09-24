
#include<bits/stdc++.h>
using namespace std;
#define ll long long 
//Fast Modulo
ll fastmodulo(ll a, ll b, ll m) {
	ll res = 1;
	ll ans = a;
	while (b > 0) {
		if (b & 1) {
			res = (res * a) % m;
		}
		a = (a * a) % m;
		b = b >> 1;
	}

	return res;

	

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

cout << fastmodulo(5, 3, 100 ) << endl;


    return 0;





