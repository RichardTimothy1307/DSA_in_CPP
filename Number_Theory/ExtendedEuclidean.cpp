
#include<bits/stdc++.h>
using namespace std;
//Extended Euclidian Algo
int x, y, GCD;
void extendedEuclidMethod(int a, int b) {
	//Base case
	if (b == 0) {
	x = 1; 

		y = 0;
		GCD = a;
		return;
	}
	//Recursive Case
	extendedEuclidMethod(b, a % b);
	int cx = y;
	int cy = x - (a / b) * y;

	x = cx;
	y = cy;


}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);
//Driver Code
//18x+30y=6

	extendedEuclidMethod(18, 30);
	cout << x << " " << y << endl;



    return 0;





