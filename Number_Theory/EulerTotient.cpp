
#include<bits/stdc++.h>
using namespace std;


//Coprime with n from 1 to n
int phi(int n) {
	int result = n;
	for (int i = 2; i * i <= n; i++) {
		if (n % i == 0) {
			while (n % i == 0)
				n /= i;
			result -= result / i;
		}
	}
	if (n > 1)
		result -= result / n;
	return result;
}
//Coprimes till n in nloglogn complexity
int coprimes(int n) {
	int a[n + 1];
	for (int i = 0; i <= n; i++) {
		a[i] = i;
	}

	for (int i = 2; i <= n; i++) {
		if (a[i] == i) {
			for (int j = i; j <= n; j += i) { //will jump the multiples of 2
				a[j] -= a[j] / i; //divide by prime
			}
		}
	}

	return a[n];
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);




    return 0;





