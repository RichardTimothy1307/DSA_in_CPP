
#include<bits/stdc++.h>
using namespace std;
//Sieve Prime
void prime_sieve(int *p) {

	//Mark all the even nos not prime that mark all the odd
	//numbers prime
	for (long long i = 3; i < 1000005; i += 2) {
		p[i] = 1; //traversing odd places
	}
	//Sieve of all upto 10^6

	for (long long i = 3; i < 1000005; i += 2) {

		if (p[i] == 1) { //checking for odds

			for (long long j = i * i; j < 1000005; j += i) { //jumping its multiple positions if 3 then p+3 p+2p
				p[j] = 0; //because multiple will always be not prime
			}
		}
	}

	p[0] = 0;
	p[1] = 0;
	p[2] = 1;

}
	

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

//Main driver code
	int n;
	cin >> n;
	int p[1000005] = {0};

	prime_sieve(p);

	//To print primes upto n
	for (int i = 0; i <= n; i++) {
		if (p[i] == 1) {
			cout << i << " ";
		}
	}



    return 0;

}
