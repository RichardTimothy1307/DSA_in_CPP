
#include<bits/stdc++.h>
using namespace std;

//Finding the prime factors

void printprimefactors(int n) {
	int cnt;
	vector<pair<int, int>> primefactors;
	for (int i = 2; i * i <= n; i++) {  //we will go till root n because if there isnt a factor
		if (n % i == 0) { 				//smaller than root n then there will be no greater than root n
			//keep dividing it by i till it is divisble
			cnt = 0;
			while (n % i == 0) {
				n = n / i;
				cnt++;
			}
			primefactors.push_back(make_pair(i, cnt));

		}
	}
	if (n != 1) {
		//whatever is left is a prime number
		primefactors.push_back(make_pair(n, 1));
	}

	for (auto it : primefactors) {
		cout << it.first << "^" << it.second << endl;
	}

	return;



	
}

int main() {
#ifndef ONLINE_JUDGE
	freopen("ccallinput.txt", "r", stdin);
	freopen("ccalloutput.txt", "w", stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);

//Main Drivers code
	int n;
	cin >> n;
	printprimefactors( n);



    return 0;





