#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int Linear_Search(vector<int> v, int a) {
	for (int i = 0; i < v.size(); i++) {
		if (v[i] == a) {
			return i + 1;
		}
		else {}
	}
	return -1;
}


int main() {

	vector<int> v;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int val;
		cin >> val;
		v.push_back(val);
	}
	cout << "Enter the element to search-";
	int a; cin >> a;
	//Time taken Calulation start function
	auto start = high_resolution_clock::now();

	cout << "At pos- " << Linear_Search(v, a) << endl;

	//Time Calculation stop function
	auto stop = high_resolution_clock::now();

	//Duration Taken
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;



	return 0;
}