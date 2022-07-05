/*
Put all even positioned node after odd positioned nodes
e.g. 1->2->3->4->5->6->null would become 1->3->5->2->4->6->null
*/

#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

class node{
    public:
        int val;
        node* next;
    node(int data){
        val = data;
        next = nullptr;
    }
};

void oddEven(node* &head){
    node* odd = head;
    node* even = head->next;
    node* evenStart = even;
    while (even->next != nullptr && odd->next != nullptr){
        odd->next = even->next;
        odd = odd->next;

        even->next = odd->next;
        if (odd->next != nullptr)
            even = even->next;
    }
    odd->next = evenStart;
}

// taking head by reference since we'll modify it
void append(node* &head, int val){
    node* n = new node(val);
    if (head == nullptr){
        head = n;
        return;
    }
    node* temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
}

// taking head by value since we'll not modify
void display(node* head){
    for(node* temp = head; temp != nullptr; temp = temp->next)
        cout<<temp->val<<" -> ";
    cout<<"null\n";
}


int main(){
    node* head = new node(1);
    for(int i = 2; i<=11; i++)
        append(head, i);
    
    display(head);
    oddEven(head);
    display(head);

}
