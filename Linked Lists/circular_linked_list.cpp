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

void insertAtHead(node* &head, int val){
    node* n = new node(val);
    if (head == nullptr){
        n->next = n;
        head = n;
    }
    node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
    head = n;
}

void removeAtHead(node* &head){
    node* temp = head;
    while (temp->next != head)
        temp = temp->next;
    node* todelete = head;
    head = head->next;
    temp->next = head;
    delete todelete;
}

void remove(node* &head, int pos){
    if (pos <= 0) return;
    if (pos == 1){
        removeAtHead(head);
        return;
    }
    node* temp = head;
    int count = 1;
    while (count != pos-1){
        temp = temp->next;
        count++;
    }

    node* todelete = temp->next;
    temp->next = temp->next->next;
    delete todelete;
}

void append(node* &head, int val){
    if (head == nullptr){
        insertAtHead(head, val);
        return;
    }
    node* n = new node(val);
    node* temp = head;
    while(temp->next != head)
        temp = temp->next;
    temp->next = n;
    n->next = head;
}

void display(node* head){
    node* temp = head;
    do
    {
        cout<<temp->val<<" -> ";
        temp = temp->next;
    } while (temp != head);
    
    cout<<"head\n";
}

int main(){
    node* head = new node(0);
    head->next = head;

    for (int i = 1; i<=5; i++)
        append(head, i);
    
    for (int i = -1; i>=-5; i--)
        insertAtHead(head, i);

    remove(head,6);
    remove(head,1);
    removeAtHead(head);
    
    display(head);
}