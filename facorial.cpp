#include <bits/stdc++.h>
using namespace std;

int factorial_iteration(int number){
    int factorial = 1;
    for (int i = 2; i<=number; ++i)
        factorial *= i;
    return factorial;
}

int factorial_recursion(int number){
    if (number == 0 || number == 1) 
        return 1;
    else 
        return number*factorial_recursion(number-1);
}

int main(){
    int n;
    cin>>n;
    cout<<"Iteration : "<<factorial_iteration(n)<<"\n";
    cout<<"Recursion : "<<factorial_recursion(n)<<"\n";
    return 0;
}