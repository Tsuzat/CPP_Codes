// See problem statement https://www.hackerrank.com/challenges/ctci-merge-sort/problem
#include <bits/stdc++.h>
using namespace std;

long long merge_array(int arr[], int  s, int mid, int e){
    long long inv = 0;
    
    int n1 = mid-s+1;
    int n2 = e-mid;

    int a[n1], b[n2];

    for (int i = 0; i<n1; i++) a[i] = arr[i+s];
    for (int i = 0; i<n2; i++) b[i] = arr[mid+1+i];

    int i = 0, j = 0, k = s;

    while(i<n1 and j<n2){
        if (a[i]<= b[j]){
            arr[k] = a[i];
            i++;
        }
        else{
            arr[k] = b[j];
            inv += n1-i;
            j++;
        }
        k++;
    }

    while(i<n1){
        arr[k] = a[i];
        i++; k++;
    }

    while(j<n2){
        arr[k] = b[j];
        j++; k++;
    }

    return inv;
}

long long count_inversion(int arr[], int s, int e){
    long long inv = 0;
    if(s<e){
        int mid = (s+e)/2;
        inv += count_inversion(arr, s, mid);
        inv += count_inversion(arr, mid+1, e);
        inv += merge_array(arr, s, mid, e);
    }
    return inv;
}

int main(){
    int arr[] = {2, 1, 3, 1, 2};
    cout<<count_inversion(arr, 0, 4);
}