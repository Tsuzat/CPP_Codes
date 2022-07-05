#include<bits/stdc++.h>
using namespace std;

/* Mark all multiple of a unmarked number starting from 2 to <= sqrt(num) */
void primeNumbers(int n){
    bool arr[n+1];
    for (int i = 0; i<n+1; i++) arr[i] = true;

    for (int i = 2; i<sqrt(n)+1;i++){
        if (arr[i]){
            for (int j = i*i; j<n+1; j+=i){
                arr[j] = false;        
            }
        }
    }

    for (int i = 2; i<n+1; i++) 
        if (arr[i]) cout<<i<<" ";
}

/* Prime factors */
void primeFactor(int n){
    int spf[n+1] = {0};
    for (int i = 2; i<=n; i++) spf[i] = i;

    for (int i = 2; i<=n; i++){
        if (spf[i] == i){
            for (int j = i*i; j<=n; j+= i){
                if (spf[j]==j) spf[j] = i;
            }
        }
    }

    while (n!=1){
        cout<<spf[n]<<" ";
        n /= spf[n];
    } 
}

/* Finding (Gretest common divisor) GCD of two numbers a and b */
int gcd(int a, int b){
    while(b!=0){
        int rem = a%b;
        a = b;
        b = rem;
    }
    return a;
} 

int main(){

    int a,b;
    cin>>a>>b;

    // primeFactor(n);
    cout<<gcd(a,b);    

    return 0;
}