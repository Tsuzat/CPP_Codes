#include<bits/stdc++.h>
using namespace std;

/* Placing N queens in a n*n chessboard 
such that one can not kill another */

bool canPlaced(int** arr, int n, int row, int col){
	int i,j;

	//checking in same col
	for (i = 0; i<n; i++){
		if (arr[i][col] == 1) return false;
	}

	//checking in main diagonal
	// up direction
	i = row, j = col;
	while(i>=0 and j<n){
		if (arr[i][j] == 1) return false;
		i--;
		j++;
	}

	//checking in another diagonal
	// up direction
	i = row, j = col;
	while(i>=0 and j>=0){
		if (arr[i][j] == 1) return false;
		i--;
		j--;
	}	

	//return true otherwise 
	return true;
}

bool placeNQueen(int** arr, int n, int row){
	//return true if all rows are filled
	if (row>=n){
		return true;
	}
	
	// trying for each col in a row
	for (int col = 0; col<n; col++){
		if (canPlaced(arr,n,row,col)){
			// placing queen if safe
			arr[row][col] = 1;
			// checking if this is a solution
			if (placeNQueen(arr,n,row+1)){
				return true;
			}
			arr[row][col] = 0; // backtracking
		}
	}
	// return false in all other cases
	return false;
}

int main(){
    int n; // board size
    cin>>n;

    int** arr = new int* [n];

    for (int i = 0; i<n; i++){
        arr[i] = new int[n];
    }

    // intiating board with 0
    for (int i = 0; i<n; i++)
        for (int j = 0; j<n; j ++) arr[i][j] = 0;
    
    if (placeNQueen(arr,n,0))
        for (int i = 0; i<n; i++){
            for (int j = 0; j<n; j ++) cout<<arr[i][j];
            cout<<"\n";
        }
	else cout<<"NO SOLUTION";
}
