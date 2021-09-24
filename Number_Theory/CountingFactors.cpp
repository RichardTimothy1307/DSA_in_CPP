#include<bits/stdc++.h>
using namespace std;
#define ll long long 
vector<ll> primes;
const ll N = 10000005;
ll int p[N] = {0};
set<ll> s;
void seive() {
	p[0] = p[1] = 1;
	primes.push_back(2);
	s.insert(4);
	for (ll int i = 2; i < N; i += 2) {
		p[i] = 1; //not prime
	}
	for (ll int i = 3; i < N; i++) {
		if (p[i] == 0) {
			primes.push_back(i);
			s.insert(i * i);
			for (ll int j = i * i; j < N; j += i) {
				p[j] = 1;
			}
		}
	}
}
vector<int> factors;
ll int countfactors(ll n) {
	int ans = 1;
	int count;
	for (ll int i = 0; primes[i]*primes[i] <= n; i++) {
		if (n % primes[i] == 0) {
			count = 0; //for every new number we count its occurences
			factors.push_back(primes[i]);
			while (n % primes[i] == 0) {
				count++;
				n /= primes[i];
			}
			ans = ans * (count + 1); //not outside the if condition but outside the while condition
		}

	}
	if (n > 1) {
		ans = ans * 2;
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




    return 0;


