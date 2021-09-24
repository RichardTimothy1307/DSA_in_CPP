#include<bits/stdc++.h>
using namespace std;

bool isprime(long long no) {
	if (no <= n) {
		return b[no] == 1 ? true : false;
	}
	//We will check in the prime vector
	for (long long int i = 0; primes[i] * (long long)primes[i] < no; i++) { //This will take root N times complexity
		if (no % primes[i] == 0) {
			return false;
		}
	}
	return true;

}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	//Drivers code
	sieve();

	//2147483647
	if (isprime(2147483648)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}


    return 0;





