
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
//Pass the a and m to get b that is multiplicative inverse of a
//such that ab%m gives us
//AX+BY=1 gcd(A,B)=1 Here B is M and X is the real B
int inverseModulo(int a, int m) {
	extendedEuclidMethod(a, m);
	int b = x; //the X is the equation

	return (b + m) % m;

	

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

    //Driver Code
	//If gcd(a,m) is 1
	cout << inverseModulo(8, 7) << endl;


    return 0;





