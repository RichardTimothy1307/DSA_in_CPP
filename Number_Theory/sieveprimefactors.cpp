#include<bits/stdc++.h>
using namespace std;

//Prime Factors using sieve

vector<int> primeSieve(int *p, int n) {
	p[0] = p[1] = 0;
	p[2] = 1;
	vector<int> primes;
	primes.push_back(2);
	for (int i = 3; i <= n; i += 2) {
		p[i] = 1;
	}
	for (int i = 3; i <= n; i++) {
		if (p[i] == 1) {
			primes.push_back(i);
			for (int j = i * i; j <= n; j += i) {
				p[j] = 0;
			}
		}
	}

	return primes;
}

vector<int> factorize(int m, vector<int> &primes) {
	vector<int> factors;
	factors.clear();

	int i = 0;
	int p = primes[0];
	while (p * p <= m) {
		if (m % p == 0) {
			factors.push_back(p);
			while (m % p == 0) {
				m = m / p;
			}
		}
		i++;
		p = primes[i];
	}
	if (m != 1) {
		factors.push_back(m);
	}

	return factors;

	
}


int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

//Driver Code

	int N = 1000000;
	int p[N] = {0};
	vector<int> primes = primeSieve(p, 10000);

	int no;
	cin >> no;

	vector<int> factors = factorize(no, primes);
	for (auto it : factors) {
		cout << it << endl;
	}


    return 0;





