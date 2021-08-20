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
    Node* head;
    public:
        int lenght;
        // constructor
        LinkedList(Node &node){
            head = &node;
            lenght = 1;
        }

        // to display linked list
        void display(){
            Node* temp = head;
            while(temp != NULL){
                cout<<temp->value<<" -> ";
                temp = temp->next;
            }
            cout<<"NULL";
        }

        // append
        void append(Node &node){
            // exception is when same nodes are passed multiple times
            Node* temp = head;
            while(temp->next != NULL) temp = temp->next;
            temp->next = &node;
            lenght ++;
        }

        // insert in the begining of linked list
        void insert_head(Node &node){
            Node* temp = new Node();
            temp->value = head->value;
            temp->next = head->next;
            head = &node;
            head->next = temp;
            lenght++;
        }

        // returns true if there is a node with given value; else false
        bool find(int val){
            for (Node* temp = head; temp != NULL; temp = temp->next)
                if (temp->value == val) return true;
            return false;
        }

        // returns the pointer of a node with given value
        Node* find_pointer(int val){
            for (Node* temp = head; temp != NULL; temp = temp->next)
                if (temp->value == val) return temp;
            return NULL;
        }

        void delete_by_value(int val){
            if (!find(val)){
                cout<<"\nvalue is not in linked list"<<endl;
                return;
            }
            Node* temp;
            for (temp = head; temp->next != NULL; temp = temp->next)
                if (temp->next->value == val) break;
            temp->next = temp->next->next;
            lenght--;
        }
        
        // will throw error if there is only head is left
        void pop(){
            if (lenght <= 1) return;
            Node* temp;
            for (temp = head; temp->next->next != NULL; temp=temp->next);
            temp->next = NULL;
            lenght--;
        }

        void reverse(){
            Node* previous = NULL;
            Node* current = head;
            Node* next_ptr;
            while(current != NULL){
                next_ptr = current->next;
                current->next = previous;

                previous = current;
                current = next_ptr;
            }
            head = previous;
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
    cout<<"\nlenght of LinkedList: "<<llist.lenght;

    // deleting 5
    llist.delete_by_value(5);
    cout<<endl;
    llist.display();
    cout<<"\nlenght of LinkedList: "<<llist.lenght;

    // reversing the linked list
    llist.reverse();
    cout<<"\nReversed Linked_list: ";
    llist.display();
    return 0;
}