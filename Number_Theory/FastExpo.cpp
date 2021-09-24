
#include<bits/stdc++.h>
using namespace std;

int pow(int a, int n) {
	if (n == 0) {
		return 1;
	}
	//check if n is odd
	int subprob = pow(a, n / 2);
	if (n & 1) {
		return a * subprob * subprob;
	}
	return subprob * subprob;
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);




    return 0;


}


