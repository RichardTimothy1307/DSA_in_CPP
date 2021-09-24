
#include<bits/stdc++.h>
using namespace std;

int gcdandeuclid(int a, int b, int& x, int& y) {
	if (b == 0) {
		x = 1;
		y = 0;
		return a;
	}
	int x1, y1;
	int d = gcdandeuclid(b, a % b, x1, y1);
	x = y1;
	y = x1 - (a / b) * y1;

	return d;
}

bool lde(int a, int b, int c, int& x, int& y) {
	int g = gcdandeuclid(abs(a), abs(b), x, y);
	if (c % g != 0) {
		return false;
	}

	x = x * c / g;
	y = y * c / g;
	if (a < 0) x = -x;
	if (b < 0) y = -y;
	return true;


	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

//Driver Code
	int a, b, x, y;
	a = 18;
	b = 30;
	cout << gcdandeuclid( a, b, x, y) << endl;
	cout << x << y << endl;



    return 0;





