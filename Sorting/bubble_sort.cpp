#include<bits/stdc++.h>
using namespace std;


void bubbleSort(int arr[], int n)
{

	if (n == 1)
		return;

	for (int i = 0; i < n - 1; i++)
		if (arr[i] > arr[i + 1])
		{
			int c = arr[i];
			arr[i] = arr[i + 1];
			arr[i + 1] = c;

		}
	bubbleSort(arr, n - 1);
}

int main() {

	int arr[5];
	for (int i = 0; i < 5; i++) {
		cin >> arr[i];
	}
	bubbleSort(arr, 5);

	for (auto v : arr)
		cout << v << " ";




}