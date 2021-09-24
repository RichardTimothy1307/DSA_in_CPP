#include<bits/stdc++.h>
using namespace std;
//No of divisors seive method
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
int noofdivisors(int m, vector<int> &primes) {


	int i = 0;
	int p = primes[0];
	int ans = 1;
	while (p * p <= m) {
		if (m % p == 0) {
			int cnt = 0;
			while (m % p == 0) {
				cnt++;
				m = m / p;
			}

			ans = ans * (cnt + 1); // say 2^2 so we have 0 1 and 2 therefore count+1;
		}
		i++;
		p = primes[i];
	}
	if (m != 1) {
		ans = ans * 2; //prime number left with power 0 or 1 so 2
	}

	return ans;

	

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
	int divs = noofdivisors(no, primes);
	cout << divs << endl;


    return 0;





