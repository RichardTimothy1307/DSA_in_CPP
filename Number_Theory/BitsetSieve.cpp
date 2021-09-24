#include<bits/stdc++.h>
using namespace std;

//Bitset Sieve
//Space optimised Sieve using Bitset      b[100]-> 100 bytes bitset<100> -> 100 bits
//Checking if a large no is prime or not 10^14

const int n = 10000000;
bitset<10000005> b;

vector<int> primes;

void sieve() {
	//set all bits
	b.set(); //1,1,1,1
	b[0] = b[1] = 0;
	for (long long i = 2; i <= n; i++) {
		if (b[i]) {  //go thru all numbers then mark all its multiples 0
			primes.push_back(i);
			for (long long j = i * i; j <= n; j += i) {
				b[j] = 0;
			}
		}
	}

	
}
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
//Driver Code
	sieve();
	for (int i = 0; i <= 100; i++) {
		cout << primes[i] << " ";
	}

//primechecker
//Drivers code
	sieve();

	//2147483647
	if (isprime(2147483648)) {
		cout << "Yes" << endl;
	} else {
		cout << "No" << endl;
	}


    return 0;





