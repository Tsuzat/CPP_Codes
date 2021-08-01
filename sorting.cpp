#include <bits/stdc++.h>
using namespace std;


// selection sort algorithm //////////////////////////////////
void selection_sort(int arr[], int n) { // arr is array and n is size of array

	for (int i = 0; i < n; ++i) {

		int mini_posi = i; // let current position is of smallest element

		for (int j = i + 1; j < n; j++) {
		if (arr[mini_posi] > arr[j]) {
			mini_posi = j;
		}
		}
		int temp = arr[mini_posi];
		arr[mini_posi] = arr[i];
		arr[i] = temp;
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
////////////////////////////////////////////////////////////////

// bubble sort algorithm //////////////////////////////////

void bubble_sort(int arr[], int n) {

	for (int i = 1; i < n; ++i) {
		for (int j = 0; j < n - i - 1; j++) {
		if (arr[j] > arr[j + 1]) {
			int temp = arr[j];
			arr[j] = arr[j + 1];
			arr[j + 1] = temp;
		}
		}
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}
////////////////////////////////////////////////////////////////

// insertion sort algorithm //////////////////////////////////

void insertion_sort(int arr[], int n) {

	int pivot = 1, current, i;
	while (pivot < n) {
		int current = arr[pivot];
		i = pivot - 1;
		while (arr[i] > current && i >= 0) {
		arr[i + 1] = arr[i];
		i--;
		}
		arr[i + 1] = current;
		pivot++;
	}

	for (int i = 0; i < n; ++i)
		cout << arr[i] << " ";
	cout << "\n";
}

////////////////////////////////////////////////////////////////

int main() {

	int n = 5;
	int arr[] = {3, 4, 2, 1, 5};

	cout << "\nSelection sort: ";
	selection_sort(arr, n); // selection_sort
	cout << "\nBubble sort: ";
	bubble_sort(arr, n); // bubble_sort
	cout << "\ninsertion sort: ";
	insertion_sort(arr, n); // insertion_sort

	return 0;
}
