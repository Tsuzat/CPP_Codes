#include <iostream>
using namespace std;

void wave_sort(int arr[], int n){
    for (int i = 1; i<n-1; i+=2){
        if (arr[i]>arr[i-1]) swap(arr[i], arr[i-1]);
        if (arr[i]>arr[i+1]) swap(arr[i], arr[i+1]);
    }
}

int main(){
    int arr[] = {1, 3, 4, 7, 5, 6, 2, 0};
    wave_sort(arr,8);
    for (int i = 0; i<8; i++) cout<<arr[i]<<" ";
}