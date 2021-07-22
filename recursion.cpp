#include<bits/stdc++.h>
using namespace std;

/*To check if an array is sorted using recursion*/
bool isSorted(int arr[], int n){
    if (n==1) 
        return true;
    return (arr[0]<=arr[1] && isSorted(arr+1,n-1));
}

/* Print a string in reverse */
void reversePrint(char s[]){
    if (s[0]== '\0'){
        return;
    }
    else{
        reversePrint(s+1);
        cout<<s[0];
    } 
}   

/* Tower of Hanoi */
void towerOfHanoi(int n, char i, char t, char h){

    if (n==0) 
        return;

    towerOfHanoi(n-1, i, h, t);
    cout<<"Move the "<<n<<"th disk from "<<i<<" to "<<t;
    cout<<endl;
    towerOfHanoi(n-1,h, t, i);
}

/*Remove the continueous duplicates*/
string removeDuplicates(string s){
    if (s.length()==0)
        return "";
    
    char ch = s[0];
    string temp = removeDuplicates(s.substr(1));
    if (ch == temp[0]){
        return temp;
    }
    
    return (ch+temp);
}

/*Move all X's at the end of the string*/
void moveXs(char s[]){
    if (s[0]=='\0')
        return;
    
    if (s[0] == 'x'){
        moveXs(s+1);
        cout<<s[0];
    }
    else{
        cout<<s[0];
        moveXs(s+1);
    }
}

/* Generate all possible substrings of a given string */
void generateSubstring(string s,int pointer, string ans){
    if (pointer == s.length()){
        cout<<'{'<<ans<<'}'<<endl;
        return;
    }

    // excluding pointer value
    generateSubstring(s,pointer+1,ans);

    // including pointer value
    generateSubstring(s,pointer+1,(ans+s[pointer]));
}

/* Generate permutations */
void permutation(string s, string ans){
    if (s.length()==0){
        cout<<ans<<endl;
        return;
    }
    for (int i = 0; i<s.length(); i++){
        string s_left = s.substr(0,i)+s.substr(i+1);
        permutation(s_left,ans+s[i]);
    }
}

/* Count the number of ways to jump from 0 */
int waysToReach(int start, int end){
    if (start == end) return 1;
    if (start > end) return 0;

    int count = 0;
    for (int dice = 1; dice<=6; dice++){
        count += waysToReach(start+dice,end);
    }
    return count;
}

/* count all possible ways maze */
int possibleMazePaths(int n, int x, int y){
    if (x==n-1 and y==n-1) return 1;
    
    if (x>=n or y>=n ) return 0;

    return possibleMazePaths(n,x+1,y)+possibleMazePaths(n,x,y+1);
}

/* snapsack: given items with weight and value and maximum capacity
You need to find maximum value can be fitted in given capacity */
int snapSack(int value[], int wt[], int n, int W){

    if(n<=0 || W<=0) return 0;

    return max(snapSack(value,wt,n-1,W-wt[n-1])+value[n-1], snapSack(value,wt,n-1,W));
}

int main(){

    int n,W;
    cin>>n>>W;
    int value[n],wt[n];

    for(int i = 0; i<n ; i++) cin>>wt[i];
    for(int i = 0; i<n ; i++) cin>>value[i];
    
    cout<<snapSack(value,wt,n,W);

    return 0;
}