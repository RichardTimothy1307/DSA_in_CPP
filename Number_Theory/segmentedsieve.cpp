#include<bits/stdc++.h>
using namespace std;

//sieve of erasthoneses which generates primes and puts in vector
const int N = 100000;

vector<int> primes;

int p[N] = {0};

void sieve() {
	for (long long i = 2; i <= N; i++) {
		if (p[i] == 0) { //it is prime
			//mark all multiples of i as not prime
			primes.push_back(i);
			for (int j = i; j <= N; j += i) {
				p[j] = 1; //not prime
			}
		}
	}
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

	//Main we take two numbers
	int n, m;
	cin >> m >> n;
	bool segment[n - m + 1];
	for (int i = 0; i < n - m + 1; i++) {
		segment[i] = 0;
	}

	//here segmented sieve logic
	for (auto x : primes) {
		if (x * x > n) { //if remaining primes are not needed
			break;
		}
		int start = (m / x) * x;

		if (m <= x and x <= n) { //prime lies between seg sieve range
			start = 2 * x;
		}


		//mark all multiples of x,in the range start to n as not primes
		for (int i = start; i <= n; i += x) {
			segment[i - m] = 1; //using 0 for prime and 1 for not prime   always will be i-m because i goes till m then m+1 m+2
		}
	}

	//loop over m..n and print the primes
	for (int i = m; i <= n; i++) {
		if (segment[i - m] == 0 and i != 1) {
			cout << i << endl;
		}
	}
	cout << endl;

    return 0;





