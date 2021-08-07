#include <bits/stdc++.h>
using namespace std;

class Node{
    public:
        int value;
        Node* next;

        Node(){}

        Node(int val){
            value = val;
            next = NULL;
        }
};

class LinkedList {
    Node head;
    int len;
    public:
        // constructor
        LinkedList(Node &node){
            head = node;
            len = 1;
        }

        // to display linked list
        void display(){
            Node* temp = &head;
            while(temp != NULL){
                cout<<temp->value<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL";
        }

        // append
        void append(Node &node){
            // exception is when same nodes are passed multiple times
            Node* temp = &head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = &node;
            len ++;
        }

        // insert in the begining of linked list
        void insert_head(Node &node){
            Node* temp = new Node();
            temp->value = head.value;
            temp->next = head.next;
            head = node;
            head.next = temp;
            len++;
        }

        int lenght(){
            return len; 
        }
};

int main(){

    Node head(1); // initialising head node for LinkedList
    LinkedList llist(head);
    
    Node arr[4];

    // inserting elements in back
    for (int i = 0; i<4; i++){
        Node temp(i+2);
        arr[i] = temp;
        llist.append(arr[i]);
    }

    Node arr1[4];
    // inserting element in head
    for (int i = 0; i<4; i++){
        Node temp1(-i);
        arr1[i] = temp1;
        llist.insert_head(arr1[i]);        
    }
    
    // printing LinkedList
    llist.display();
    cout<<"\nlenght of LinkedList: "<<llist.lenght();
    return 0;
}