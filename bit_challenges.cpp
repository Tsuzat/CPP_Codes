#include<bits/stdc++.h>
using namespace std;

/* returns true (1) if num is a power of 2
taking an edge case if n=0 */
int isPowerOf2(int num){
    return (num && !(num & num-1));
}

/* Counting 1s in a number's binary */
int numberOf1s(int num){
    int count = 0;
    while (num){
        num = num & (num-1);
        count ++;
    }
    return count;
}

/* Making all possible subset of a given set */
void subSet(int arr[], int n){
    for (int i = 0; i < (1<<n); i++){
        for (int j = 0; j<n; j++){
            if (i & (1<<j)) cout<<arr[j]<<" ";
        }
        cout<<endl;
    }
}

/* finding the unique numbers using xor operator (time complexity : O(n*n) */
void uniqueNumUsingXOR(int arr[],int n){
    for (int i= 0; i<n; i++){
        bool unique = true;
        for (int j = 0; j<n && unique; j++){
            if (i==j) continue;
            else{
                if (!(arr[i] xor arr[j])) unique = false;
            }
        }
        if (unique) cout<<arr[i]<<" ";
    }
}

int main(){

    // int num;
    // cin>>num;

    int n;
    cin>>n;
    int arr[n];
    for (int i = 0; i<n; i++) cin>>arr[i];

    uniqueNumUsingXOR(arr,n);

    // cout<<isPowerOf2(num);
    // cout<<numberOf1s(num);

    return 0;
}
