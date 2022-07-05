#include "bits/stdc++.h"
using namespace std;

void count_sort(int arr[], int n){
    int mx = INT_MIN; // initial value of mx

    for (int i = 0; i<n; i++) mx = max(arr[i], mx); // getting the maximum element in arr

    int freq[mx+1]; // an array of size mx+1
    for (int i = 0; i<mx+1; i++) freq[i] = 0; // initialising freqencies with 0

    for (int i = 0; i<n; i++) freq[arr[i]] ++; // storing the freqencies

    for (int i = 1; i<mx+1; i++) freq[i] += freq[i-1]; // modifying the fequencies

    int ans[n]; // to store sorted array
    for (int i = n-1; i>=0; i--){
        ans[--freq[arr[i]]] = arr[i];
    }
    for (int i = 0; i<n; i++) cout<<ans[i]<<" "; // printing sorted array
}

int main(){
    int arr[] = {3, 4, 5, 1, 4, 2};
    count_sort(arr, 6);
}