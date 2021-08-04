#include <bits/stdc++.h>
using namespace std;


void merge(int arr[], int const s, int const mid, int const e){
	// size of first half;
	int const n1 = mid-s+1;
	// size of right half
	int const n2 = e-mid;
	// temp1 to store first half of the arr
	int* temp1 = new int[n1];
	for (int i = 0; i<n1; i++) temp1[i] = arr[s+i];
	int* temp2 = new int[n2];
	for (int i = 0; i<n2; i++) temp2[i] = arr[mid+1+i];


	// making index pointers-> p1 for temp1, p2 for temp2 and k for arr
	int p1 = 0, p2 = 0, k = s;
	while (p1<n1 && p2<n2){
		if (temp1[p1]<temp2[p2]){
			arr[k] = temp1[p1];
			p1++;
		}
		else{
			arr[k] = temp2[p2];
			p2++;
		}
		k++;
	}

	// checking if any of temp has un-checked element
	while(p1<n1){
		arr[k] = temp1[p1];
		p1++;
		k++;
	}

	while(p2<n2){
		arr[k] = temp2[p2];
		p2++;
		k++;
	}
}

void merge_sort(int arr[], int const s, int const e){
	if (s<e){
		int mid = (s+e)/2;
		//sort left half
		merge_sort(arr, s, mid);
		//sort right half
		merge_sort(arr, mid+1, e);
		//merge sorted halfs
		merge(arr, s, mid, e);
	}
}

int main(){
	int arr[] = {3, 1, 5, 4, 2}; 
	merge_sort(arr, 0, 4);
	for (int i = 0; i<5; i++) cout<<arr[i]<<" ";
}