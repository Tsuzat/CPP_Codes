#include <iostream>
#include <stack>
using namespace std;

void insertAtBottom(stack<int> &st, int ele){
    if (st.empty()){
        st.push(ele);
        return;
    }
    int topele = st.top();
    st.pop();
    insertAtBottom(st,ele);
    st.push(topele);
}


void reverseStack(stack<int> &st){
    if (st.empty()) return;
    int last = st.top();
    st.pop();
    reverseStack(st);
    insertAtBottom(st, last);
}

void print(stack<int> s){
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
    cout<<"\n";
}

int main(){
    stack<int> st;
    for (int i= 1; i<=10; i++) st.push(i);
    cout<<"Stack: ";
    print(st);
    reverseStack(st);
    cout<<"Reversed Stack: ";
    print(st);
    return 0;
}