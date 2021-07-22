#include<bits/stdc++.h>
using namespace std; 

// get bit at ith position
int getBit(int mask, int i){
    return (mask>>i) & 1;
}

// set 1 at ith position
int setBit(int mask, int i){ 
    return mask | (1<<i);
}

// clear bit at ith position
int clearBit(int mask, int i){
    return mask & (~(1<<i));
}

// toggle bit at ith postion (0->1 or 1->0)
int toggleBit(int mask, int i){
    return mask xor (1<<i);
}

// update bit at ith postion with given value (1 or 0)
int updateBit(int mask, int i, int value){
    mask = clearBit(mask,i);
    return mask | (value<<i);
}

int main(){
    int n,i,value;
    cin>>n>>i>>value;

    //cout<<getBit(n,3);
    cout<<updateBit(n,i,value);

    return 0;
}