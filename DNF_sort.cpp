#include <bits/stdc++.h>
using namespace std;

void dnf_sort(int arr[], int n){
    int low = 0, mid = 0, high = n-1;

    while(mid<=high){
        switch (arr[mid]){
            case 0 : 
                swap(arr[mid++], arr[low++]);
                break;

            case 1 : 
                mid++;
                break;

            case 2 : 
                swap(arr[mid],arr[high--]);
                break;
        }
    }
}

int main(){
    int arr[] = {2, 2, 1, 0, 2, 1, 0, 1, 1};
    dnf_sort(arr,9);
    for (int i = 0; i<9; i++) cout<<arr[i]<<" ";
    return 0;
}