#include<bits/stdc++.h>
using namespace std;

bool canGo(int** arr, int x, int y, int n){
    if (x<n && y<n && arr[x][y] == 1 ) return true;
    return false;
}

/* Rat in the maze */
bool ratInMaze(int** arr, int** ans, int x, int y, int n){
    if (x == n-1 && y == n-1 ){
        ans[x][y] = 1;
        return true;
    }

    if (canGo(arr,x,y,n)){
        ans[x][y] = 1;
        if (ratInMaze(arr,ans,x+1,y,n)) return true;
        if (ratInMaze(arr,ans,x,y+1,n)) return true;
        //otherwise
        ans[x][y] = 0;
        return false;
    }

    return false;
}

int main(){

    int n;
    cin>>n;

    int** arr = new int*[n];
    int** ans = new int*[n];

    for (int i = 0; i<n ; i++){
        arr[i] = new int [n];
        ans[i] = new int [n];
    }

    
    for (int i = 0; i < n; i++)
        for (int j = 0; j<n ;j++) cin>>arr[i][j];
    
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j++) ans[i][j] = 0;


    // check for the solution
    if (ratInMaze(arr,ans,0,0,n)){
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j++) cout<<ans[i][j]<<" ";
            cout<<"\n";
        }
    }
    // if therse is no solution 
    else cout<<"NO SOLUTION";

    return 0;
}