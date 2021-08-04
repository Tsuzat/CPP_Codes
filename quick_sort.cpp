#include <bits/stdc++.h>
using namespace std;

// swaping two variables
void swap(int* a, int* b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

int partition(int arr[], int l, int r){
    int pivot = arr[r];
    int i = l-1;
    for (int j = l; j<=r-1; j++){
        if (arr[j]<pivot){
            i ++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i+1], &arr[r]);
    return i+1;
}

void quick_sort(int arr[], int l, int r){
    if (l<r){
        int p = partition(arr, l, r);
        quick_sort(arr, l, p-1);
        quick_sort(arr, p+1, r);
    }
}

int main(){
    int arr[] = {3, 5, 1, 4, 4, 2};
    quick_sort(arr, 0, 5);
    for (int i = 0; i<6; i++) cout<<arr[i]<<" ";
}