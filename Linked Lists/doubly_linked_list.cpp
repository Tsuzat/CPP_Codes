#include <bits/stdc++.h>
using namespace std;

#define endl '\n'

class node {
  public:
    int val;
    node *next;
    node *prev;

    node(int data) {
        val = data;
        next = nullptr;
        prev = nullptr;
    }
};

// passing by reference coz head is being changed
void insertAtHead(node *&head, int val) {
    node *n = new node(val);
    if (head == nullptr) {
        head = n;
        return;
    }
    n->next = head;
    head->prev = n;
    head = n;
}

// passing by reference coz head is being changed
void append(node *&head, int val) {
    node *n = new node(val);
    if (head == nullptr) {
        head = n;
        return;
    }
    node *temp = head;
    while (temp->next != nullptr)
        temp = temp->next;
    temp->next = n;
    n->prev = temp;
}

// passing by reference coz head is being changed
void remove(node *&head, int val) {
    node *temp = head;

    if (head->val == val) {
        head = head->next;
        head->prev = nullptr;
        delete temp;
        return;
    }
    while (temp != nullptr && temp->val != val)
        temp = temp->next;
    temp->prev->next = temp->next;

    if (temp->next != nullptr)
        temp->next->prev = temp->prev;
    delete temp;
}

void reverseRecuisevely(node* &head){
    if (head == nullptr) return;

    node* temp = head;
    node* upnext = head->next;
    reverseRecuisevely(upnext);
    append(upnext, head->val);
    head = upnext;
}

node* tail(node* &head){
    node* temp;
    for(temp = head; temp->next != nullptr; temp = temp ->next);
    return temp;
}

void swapValues(node* &a, node* &b){
    int temp = a->val;
    a->val = b->val;
    b->val = temp;
}

void reverseBySwap(node* &head){
    node* l = head;
    node* r = tail(head);
    while(1){
        swapValues(l,r);
        if (l->next == r || l->next == r->prev) break;
        l = l->next;
        r = r->prev;
    }
}

// passing by value since head is not being changed
void display(node* &head) {
    cout<<"null <-> ";
    for (node *temp = head; temp != nullptr; temp = temp->next)
        cout << temp->val << " <-> ";
    cout << "null\n";
}

int main() {
    node *head = nullptr;

    for (int i = 0; i <= 5; i++) {
        append(head, i);
    }

    for (int i = -1; i >= -5; i--) {
        insertAtHead(head, i);
    }

    // remove -5, 5 and 0
    /* remove(head, -5);
    remove(head, 5);
    remove(head, 0); */

    display(head);
    reverseBySwap(head);
    display(head);
    return 0;
}
