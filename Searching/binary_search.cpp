#include<bits/stdc++.h>
using namespace std;
using namespace std::chrono;

int Binary_Search(vector<int> v, int start1, int end, int a) {


	int mid = (start1 + end) / 2;
	if (start1 <= end) {


		if (v[mid] == a) {
			return mid + 1;
		}

		else if (v[mid] < a) {
			return Binary_Search(v, mid + 1, end, a);
		}

		else if (v[mid] > a) {
			return Binary_Search(v, start1, mid - 1, a);
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
	int start1 = 0;
	int end = v.size();
	cout << "Enter the element to search-";
	int a; cin >> a;
	//Time taken Calulation start function
	auto start = high_resolution_clock::now();

	cout << "At pos-" << Binary_Search(v, start1, end, a) << endl;

	//Time Calculation stop function
	auto stop = high_resolution_clock::now();

	//Duration Taken
	auto duration = duration_cast<microseconds>(stop - start);

	cout << "Time taken by function: " << duration.count() << " microseconds" << endl;





	return 0;
}